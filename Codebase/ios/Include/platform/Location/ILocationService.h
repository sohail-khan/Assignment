// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Space.h"

namespace Eegeo
{
    namespace Location
    {
        class ILocationService
        {
        public:
            virtual ~ILocationService() { }
            
            virtual const bool GetIsAuthorized() const = 0;
            
            virtual bool GetLocation(Eegeo::Space::LatLong& latlong)=0;
            virtual bool GetAltitude(double& altitude)=0;
            virtual bool GetHorizontalAccuracy(double& accuracy)=0;
            virtual bool GetHeadingDegrees(double& headingDegrees) = 0;
            virtual void StopListening() = 0;
            
        };
    }
}
