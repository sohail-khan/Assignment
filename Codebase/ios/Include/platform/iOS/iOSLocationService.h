// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ILocationService.h"
#include "Space.h"

namespace Eegeo
{
    namespace iOS
    {
        class iOSLocationService : public Eegeo::Location::ILocationService
        {
        private:
            double latRadians;
            double lonRadians;
            double altitudeMeters;
            double horizontalAccuracyMeters;
            double headingDegrees;
            bool hasLocation;
            bool hasHeading;
            bool isAuthorized;
            
        public:
            iOSLocationService();
            
            void SetAuthorized(bool authorized);
            const bool GetIsAuthorized() const { return isAuthorized; }
            
            void FailedToGetLocation();
            void FailedToGetHeading();
            void UpdateLocation(double latDegrees, double lonDegrees, double altitudeMeters);
            void UpdateHorizontalAccuracy(double accuracyMeters);
            void UpdateHeading(double heading);
            
            bool GetLocation(Eegeo::Space::LatLong& latlong);
            bool GetAltitude(double& altitude);
            bool GetHorizontalAccuracy(double& accuracy);
            bool GetHeadingDegrees(double& heading);
            void StopListening(){};
        };
    }
}