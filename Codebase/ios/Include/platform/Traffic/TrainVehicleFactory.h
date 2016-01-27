// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Navigation.h"
#include "IVehicleFactory.h"
#include "Traffic.h"
#include "Location.h"
#include "Random.h"
#include "TrafficSimulationConfiguration.h"
#include "ParsedNavGraph.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Traffic
    {
        using Resources::Roads::Navigation::NavigationGraph;
        
        
         struct ClosestVehicle
        {
            IVehicle* vehicle;
            double distance;
            
            ClosestVehicle(IVehicle* vehicle, double distance) : vehicle(vehicle), distance(distance)
            {
            }
        };
        
        class TrainVehicleFactory : public IVehicleFactory
        {
        public:
            
            TrainVehicleFactory(const Config::TrafficSimulationConfiguration& config,
                                Random& randomGenerator,
                                const TrafficSimulationCellsModel* cellsModel);
            
            void CreateVehicles(int vehicleCount, const NavigationGraph& navGraph, TVehicleVector& vehicles);
            
            void SetConfig(const Config::TrafficSimulationConfiguration& roadConfig);
            void ApplyVehicleSuffixChange(const std::string &suffix);
            
            int CalcInitialVehicleCount(const NavigationGraph& navGraph);
            
        private:
            const ClosestVehicle GetNearestTrainVehicle(const Eegeo::dv3& ecefPosition);
            const TrafficSimulationCellsModel* m_cellsModel;
            Config::TrafficSimulationConfiguration m_config;
            Random& m_random;
            std::string m_modelNodeSuffix;
            
            std::vector<IVehicle*> CreateRandomVehicle(const NavigationGraph* navGraph,
                                                       int beginningRoadIndex) const;
            std::vector<IVehicle*> CreateRandomVehicleFromConfig(const NavigationGraph* navGraph,
                                                                 int beginningRoadIndex,
                                                                 const Config::TrafficSimulationVehicleConfiguration& vehicleConfig) const;
            std::vector<const Config::TrafficSimulationVehicleConfiguration*> GetVehicleConfigsAcceptableForRoadClass(Resources::Roads::FunctionalRoadClass functionalRoadClass) const;
        };
        
    }
}
