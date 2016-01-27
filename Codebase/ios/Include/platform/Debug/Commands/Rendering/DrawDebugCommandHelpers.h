// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "LatLongAltitude.h"
#include <sstream>
#include <vector>

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Rendering
            {
                namespace DrawDebugCommandHelpers
                {
                    bool TryParseColor(const std::vector<std::string> &arguments, int index, v4& colour);
                    
                    bool TryParseLatLongAlt(const std::vector<std::string> &arguments, int index, Space::LatLongAltitude& latLongAltitude);
                }
            }
        }
    }
}