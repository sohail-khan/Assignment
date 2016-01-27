// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <LocationApi.h>
#include "ILocationService.h"
#include "Types.h"

struct WindowsNativeState;

namespace Eegeo
{
	namespace Windows
	{
        struct LocationOverride
        {
            double latRadians;
            double lonRadians;
            double altitudeMeters;
            double horizontalAccuracyMeters;
            double headingDegrees;
        };

		class WindowsLocationService : public Eegeo::Location::ILocationService, protected Eegeo::NonCopyable
		{
	        private:
                LocationOverride* m_pLocationOverride;
	            double latRadians;
	            double lonRadians;
	            double altitudeMeters;
	            double horizontalAccuracyMeters;
	            double headingDegrees;
	            bool hasLocation;
	            bool hasAccuracy;
	            bool hasAltitude;
	            bool hasHeading;
	            bool isAuthorized;

				WindowsNativeState* pState;

	            void UpdateLatLong();
	            void UpdateHeading();

                CComPtr<ILocation> m_pLocationService;

	        public:
	            WindowsLocationService(WindowsNativeState* pState, LocationOverride* locationOverride = NULL);
	            ~WindowsLocationService();

	            void StopListening();

	            const bool GetIsAuthorized() const { return isAuthorized; }
	            bool GetLocation(Eegeo::Space::LatLong& latlong);
	            bool GetAltitude(double& altitude);
	            bool GetHorizontalAccuracy(double& accuracy);
	            bool GetHeadingDegrees(double& headingDegrees);
		};
	}
}
