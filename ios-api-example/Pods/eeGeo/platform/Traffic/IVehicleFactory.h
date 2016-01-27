// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Traffic.h"
#include "Navigation.h"
#include <string>

namespace Eegeo
{
    namespace Traffic
    {
        using Resources::Roads::Navigation::NavigationGraph;
        
        class IVehicleFactory
        {
        public:
            virtual ~IVehicleFactory() { };
            virtual void CreateVehicles(int vehicleCount, const NavigationGraph& navGraph, TVehicleVector& vehicles) = 0;
            
            virtual int CalcInitialVehicleCount(const NavigationGraph& navGraph) = 0;
            
            virtual void SetConfig(const Config::TrafficSimulationConfiguration& config) = 0;
            virtual void ApplyVehicleSuffixChange(const std::string &suffix) = 0;

        };
    }
}