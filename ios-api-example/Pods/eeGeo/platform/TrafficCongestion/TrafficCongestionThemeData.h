// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Traffic.h"

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class TrafficCongestionThemeData
        {
        public:
            const Traffic::Config::TrafficSimulationConfiguration& configuration;

            TrafficCongestionThemeData(const Traffic::Config::TrafficSimulationConfiguration& configuration)
            : configuration(configuration)
            {

            }
        };
    }
}

