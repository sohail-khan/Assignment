// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "ControlCityThemeExample.h"
#include "ICityThemesUpdater.h"
#include "ICityThemesService.h"
#include "ICityThemeRepository.h"
#include "CityThemeData.h"
#include "EegeoWorld.h"
#include "Logger.h"

namespace
{
bool PointInPolygon(std::vector<Eegeo::v2>& polygon, Eegeo::v2& point)
{
	int i = 0;
	int j = 0;
	bool result = false;
	int numVerts = static_cast<int>(polygon.size());
	for (i = 0, j = numVerts-1; i < numVerts; j = i++)
	{
		if (((polygon[i].GetY()>point.GetY()) != (polygon[j].GetY()>point.GetY())) &&
		        (point.GetX() < (polygon[j].GetX()-polygon[i].GetX()) *
		         (point.GetY()-polygon[i].GetY()) / (polygon[j].GetY()-polygon[i].GetY()) + polygon[i].GetX()))
		{
			result = !result;
		}
	}
	return result;
}

void VectorLatLonToV2(const std::vector<Eegeo::Space::LatLong>& input, std::vector<Eegeo::v2>& output)
{
	output.reserve(input.size());
	for (std::vector<Eegeo::Space::LatLong>::const_iterator iter = input.begin();
	        iter != input.end();
	        iter++)
	{
		const Eegeo::Space::LatLong& latLong = (*iter);
		output.push_back(Eegeo::v2(static_cast<float>(latLong.GetLatitudeInDegrees()), static_cast<float>(latLong.GetLongitudeInDegrees())));
	}
}
}

namespace Examples
{
    ControlCityThemeExample::ControlCityThemeExample(Eegeo::Resources::CityThemes::ICityThemesService& themeService,
        Eegeo::Resources::CityThemes::ICityThemeRepository& themeRepository,
        Eegeo::Resources::CityThemes::ICityThemesUpdater& themeUpdater,
        Eegeo::EegeoWorld& eegeoWorld,
        Eegeo::Camera::GlobeCamera::GlobeCameraController* pCameraController,
                        Eegeo::Camera::GlobeCamera::GlobeCameraTouchController& cameraTouchController)
	: GlobeCameraExampleBase(pCameraController, cameraTouchController)
    , m_themeService(themeService)
	,m_themeRepository(themeRepository)
	,m_themeUpdater(themeUpdater)
	,m_eegeoWorld(eegeoWorld)
	,m_themeChanged(false)
	,m_initialCityTheme(themeService.GetCurrentTheme())
{
}

void ControlCityThemeExample::Suspend()
{
	m_themeService.SetSpecificTheme(m_initialCityTheme);
	m_themeUpdater.SetEnabled(true);
    
    
}

// This method does the following:
// 1. Disables ICityThemesUpdater - so the App is in sole control of what Theme is active
// 2. Sets "SummerNewYork" as the current Theme.
void ControlCityThemeExample::ChangeTheme()
{
	const std::string themeToSelect = "SummerNewYork";

	EXAMPLE_LOG("Starting City Theme Control Example\n");

	EXAMPLE_LOG("Disabling ICityThemesUpdater control over theme selection\n");
	m_themeUpdater.SetEnabled(false);
	const bool enabled = m_themeUpdater.GetEnabled();
	EXAMPLE_LOG("ICityThemesUpdater control over theme selection: %d\n", enabled);

	EXAMPLE_LOG("Obtaining %s ThemeData\n", themeToSelect.c_str());
	const Eegeo::Resources::CityThemes::CityThemeData& themeDataToSelect = *m_themeRepository.GetThemeDataByName(themeToSelect);

	EXAMPLE_LOG("Setting %s Theme\n", themeToSelect.c_str());
	m_themeService.SetSpecificTheme(themeDataToSelect);
	EXAMPLE_LOG("%s Theme will now be downloaded and applied asynchronously. It will remain active until SetSpecificTheme is called again\n", themeToSelect.c_str());
}

void ControlCityThemeExample::FindThemeByPointInPolygon()
{
	Eegeo::Space::LatLong osaka = Eegeo::Space::LatLong::FromDegrees(34.700131,135.478884);
	Eegeo::v2 osakav2(static_cast<float>(osaka.GetLatitudeInDegrees()), static_cast<float>(osaka.GetLongitudeInDegrees()));

	// enumerate all of the themes in the theme repository
	int numberOfThemes = m_themeRepository.GetNumberOfThemes();
	for (int i=0; i<numberOfThemes; ++i)
	{
		const Eegeo::Resources::CityThemes::CityThemeData& themeData = m_themeRepository.GetCityThemeAt(i);
		if (themeData.PolygonBounds.size() > 0) // there are points in the bounding polygon
		{
			std::vector<Eegeo::v2> polygon;
			VectorLatLonToV2(themeData.PolygonBounds, polygon);
			if (PointInPolygon(polygon, osakav2))
			{
				EXAMPLE_LOG("This theme contains the Osaka point: %s\n", themeData.Name.c_str());
				return;
			}
		}
	}
	EXAMPLE_LOG("No theme found that contains the Osaka point\n");
}

void ControlCityThemeExample::Update(float dt)
{
	if (!m_themeChanged)
	{
		// This is required so that the theme manifest can be downloaded. Changing theme before EegeoWorld is Initialised will result in ICityThemeRepository being empty.
		if (!m_eegeoWorld.Initialising())
		{
			ChangeTheme();
			FindThemeByPointInPolygon();
			m_themeChanged = true;
		}
	}
}

}
