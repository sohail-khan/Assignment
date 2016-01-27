// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <map>
#include "MortonKey.h"
#include "ClippedRouteSection.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Clipping
        {
            //there can be multiple sections if a route snakes in and out of a cell
            class ClippedRoute : public std::map<Eegeo::Streaming::MortonKey, std::vector<ClippedRouteSection>, Eegeo::Streaming::MortonKeyCompare>
            {
                
            };
        }
    }
}
