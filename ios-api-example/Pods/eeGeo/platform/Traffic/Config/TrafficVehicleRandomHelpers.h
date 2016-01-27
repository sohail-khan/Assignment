// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Helpers.h"
#include "TrafficSimulationConfiguration.h"

namespace Eegeo
{
    namespace Traffic
    {
        namespace Config
        {
            void PopulateFitnessValuesForVehicles(
                    const std::vector <Eegeo::Traffic::Config::TrafficSimulationVehicleConfiguration>& vehicleConfigs,
                    std::vector<float>& out_fitnessValues);

            Eegeo::Helpers::RouletteWheelSelector* CreateRouletteWheelSelectorForVehicles(
                    const std::vector <Eegeo::Traffic::Config::TrafficSimulationVehicleConfiguration>& vehicleConfigs);
        }
    }
}