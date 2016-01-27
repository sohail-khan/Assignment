// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "ILocationService.h"

namespace Eegeo
{
    namespace OSX
    {
        class OSXLocationService  : public Eegeo::Location::ILocationService, protected Eegeo::NonCopyable
        {
        public:
            bool GetLocation(Eegeo::Space::LatLong& latlong);
            bool GetAltitude(double& altitude);
            bool GetHorizontalAccuracy(double& accuracy);
            bool GetHeadingDegrees(double& headingDegrees);
            void StopListening(){};
            const bool GetIsAuthorized() const;
        };
    }
}