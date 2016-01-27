// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IVehicleFactory.h"
#include "Traffic.h"
#include "Location.h"
#include "Random.h"
#include "Navigation.h"
#include "TrafficSimulationConfiguration.h"
#include "Helpers.h"
#include <string>

namespace Eegeo
{
    namespace Traffic
    {
        using Resources::Roads::Navigation::NavigationGraph;
        
        class CarVehicleFactory : public IVehicleFactory
        {
        public:
            
            CarVehicleFactory(const Config::TrafficSimulationConfiguration& config,
                              Random& randomGenerator,
                              const TrafficSimulationCellsModel* cellsModel);

            ~CarVehicleFactory();
            
            void CreateVehicles(int vehicleCount, const NavigationGraph& navGraph, TVehicleVector& vehicles);
            
            int CalcInitialVehicleCount(const NavigationGraph& navGraph);
            
            void SetConfig(const Config::TrafficSimulationConfiguration& roadConfig);
            void ApplyVehicleSuffixChange(const std::string &suffix);

        private:
            Config::TrafficSimulationConfiguration m_config;
            const TrafficSimulationCellsModel* m_cellsModel;
            
            Random& m_random;
            std::string m_modelNodeSuffix;
            Helpers::RouletteWheelSelector* m_pRouletteWheelSelector;
        };
    }
}
