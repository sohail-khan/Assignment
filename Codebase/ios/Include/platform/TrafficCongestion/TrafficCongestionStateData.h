// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace TrafficCongestion
    {
        struct TrafficCongestionStateData
        {
            std::string vehicleModelSuffix;

            TrafficCongestionStateData(std::string vehicleModelSuffix) : vehicleModelSuffix(vehicleModelSuffix)
            {

            }
        };
    }
}
