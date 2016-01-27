// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "VectorMath.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            struct RoadNameData
            {
                RoadNameData(std::string name,
                             Eegeo::v3 segmentStartLocalEcef,
                             Eegeo::v3 segmentEndLocalEcef,
                             float roadLength):
                name(name), segmentStartLocalEcef(segmentStartLocalEcef), segmentEndLocalEcef(segmentEndLocalEcef), roadLength(roadLength)
                {}
                
                std::string name;
                Eegeo::v3 segmentStartLocalEcef;
                Eegeo::v3 segmentEndLocalEcef;
                float roadLength;
            };
        }
    }
}
