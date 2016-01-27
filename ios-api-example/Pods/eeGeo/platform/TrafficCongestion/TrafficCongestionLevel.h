// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include <string>
#include <vector>

namespace Eegeo
{
    namespace TrafficCongestion
    {
        namespace CongestionLevel
        {
            enum CongestionLevelValues
            {
                Light = 0,
                Normal,
                Heavy,
                Gridlock
            };

            bool TryParseCongestionLevel(const std::string& s, CongestionLevelValues& out_value);
        };
    }
}
