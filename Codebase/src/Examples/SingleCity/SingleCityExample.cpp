// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "SingleCityExample.h"
#include "IStreamingVolume.h"
#include "LatLongAltitude.h"
#include "CubeMapCellInfo.h"

namespace Examples
{

namespace
{
class SphereVolume : public Eegeo::Streaming::IStreamingVolume
{
	Eegeo::dv3 m_ecefCentre;
	double m_sphereVolumeRadius;
	std::vector<Eegeo::Streaming::MortonKey> m_interesectedKeys;

public:
	SphereVolume(double lat, double lon, double radius)
		: m_ecefCentre(Eegeo::Space::LatLong::FromDegrees(lat, lon).ToECEF())
		, m_sphereVolumeRadius(radius)
	{

	}

	bool IntersectsKey(const Eegeo::Streaming::MortonKey& key,
	                   bool& canRefineIntersectedKey,
	                   double& intersectedNodeDepthSortSignedDistance)
	{
		intersectedNodeDepthSortSignedDistance = 0.0;

		printf("Testing %s in volume...\n", key.ToString().c_str());

		const Eegeo::Space::CubeMap::CubeMapCellInfo cellInfo(key);
		const Eegeo::dv3 keyEcef = cellInfo.GetFaceCentreECEF();
		const double distanceBetweenCellBoundingSphereAndVolumeSphere = (m_ecefCentre - keyEcef).Length();
		const double cellWidth = key.WidthInMetres();
		const double cellBoundingSphereRadius = std::sqrt((cellWidth*cellWidth) + (cellWidth*cellWidth));

		if(distanceBetweenCellBoundingSphereAndVolumeSphere < (m_sphereVolumeRadius + cellBoundingSphereRadius))
		{
			printf("%s in volume!\n", key.ToString().c_str());

			m_interesectedKeys.push_back(key);
			canRefineIntersectedKey = true;

			return true;
		}
		else
		{
			printf("%s NOT in volume...\n", key.ToString().c_str());
		}

		canRefineIntersectedKey = false;
		return false;
	}

	void PrintIntersectedKeys() const
	{
		printf("\n\n :: PRINTING INTERSECTED KEYS :: \n\n");

		for(std::vector<Eegeo::Streaming::MortonKey>::const_iterator it = m_interesectedKeys.begin(); it != m_interesectedKeys.end(); ++ it)
		{
			const Eegeo::Streaming::MortonKey& key = *it;
			printf("%s\n", key.ToString().c_str());
		}

		printf("\n");
	}
};
}

SingleCityExample::SingleCityExample(
                                     Eegeo::Web::PrecacheService& precacheService,
                                     Eegeo::Streaming::StreamingVolumeController& streamingVolumeController,
                                     Eegeo::EegeoWorld& world,
                                     Eegeo::Camera::GlobeCamera::GlobeCameraController* pCameraController,
                        Eegeo::Camera::GlobeCamera::GlobeCameraTouchController& cameraTouchController)
    : GlobeCameraExampleBase(pCameraController, cameraTouchController)
	, m_precacheService(precacheService)
	, m_streamingVolumeController(streamingVolumeController)
	, m_world(world)
	, m_startedPrecaching(false)
	, m_precacheComplete(false)
{

}

void SingleCityExample::Suspend()
{
	if(m_precacheService.CurrentlyPrecaching())
	{
		m_precacheService.CancelPrecaching();
	}

	m_startedPrecaching = false;
    
    
    
}

void SingleCityExample::Update(float dt)
{
	if(!m_world.Initialising() && !m_startedPrecaching && !m_precacheService.CurrentlyPrecaching())
	{
		double sphereVolumeCentreLatitudeDegrees = 37.7858;
		double sphereVolumeCentreLongitudeDegrees = -122.401;
		double sphereVolumeRadiusMetres = 3500.0;

		SphereVolume volume(sphereVolumeCentreLatitudeDegrees, sphereVolumeCentreLongitudeDegrees, sphereVolumeRadiusMetres);
		m_precacheService.Precache(volume);
		volume.PrintIntersectedKeys();
		m_startedPrecaching = true;
	}

	if(m_startedPrecaching && m_precacheService.CurrentlyPrecaching())
	{
		float toLoad = m_precacheService.TotalUrlsToLoad();
		float loaded = m_precacheService.UrlsLoaded();

		float percent = loaded/toLoad;
		int displayPercent = static_cast<int>(percent * 100.f);
		printf("Precache %d%% complete!\n", displayPercent);
	}
	else if(m_startedPrecaching && !m_precacheComplete)
	{
		printf("Precache 100%% complete!\n");
		m_precacheComplete = true;
	}
}

void SingleCityExample::EarlyUpdate(float dt)
{
    GlobeCameraExampleBase::EarlyUpdate(dt);
	ConstrainCamera();
}

void SingleCityExample::ConstrainCamera()
{
    Eegeo::Camera::GlobeCamera::GlobeCameraController& globeCamera = GetGlobeCameraController();
	Eegeo::dv3 interestPoint = globeCamera.GetInterestBasis().GetPointEcef();

	const Eegeo::Space::LatLongAltitude constrainCenter = Eegeo::Space::LatLongAltitude::FromDegrees(37.7858, -122.401, 0);
	const Eegeo::dv3 constrainCenterEcef = constrainCenter.ToECEF();
	const double radiusMeters = 2000.0;
	const double maxInterestDistance = 2000.0;

	Eegeo::dv3 offsetFromCenter = (interestPoint - constrainCenterEcef);
	double distance = offsetFromCenter.Length();

	bool tooHigh = globeCamera.GetDistanceToInterest() > maxInterestDistance;
	bool tooFar = distance > radiusMeters;

	if (tooHigh)
	{
		globeCamera.SetView(globeCamera.GetInterestBasis(), maxInterestDistance);
	}

	if(tooFar)
	{
		double interestAltitude = interestPoint.Length() - Eegeo::Space::EarthConstants::Radius;
		Eegeo::dv3 newInterestPoint = constrainCenterEcef + (offsetFromCenter.Norm() * radiusMeters);
		Eegeo::Space::LatLongAltitude newInterestPointLatLong = Eegeo::Space::LatLongAltitude::FromECEF(newInterestPoint);
		newInterestPointLatLong.SetAltitude(interestAltitude);

		Eegeo::Space::EcefTangentBasis cameraInterestBasis = globeCamera.GetInterestBasis();
		cameraInterestBasis.SetPoint(newInterestPointLatLong.ToECEF());
		globeCamera.SetInterestBasis(cameraInterestBasis);
	}

	if (tooHigh || tooFar)
	{
		// Also update the Streaming Volume as we'll have changed the position of the frustum.
		m_streamingVolumeController.Update(globeCamera.GetRenderCamera());
	}
}
}
