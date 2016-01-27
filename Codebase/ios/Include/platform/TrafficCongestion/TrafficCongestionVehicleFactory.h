// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TrafficCongestion.h"
#include "TrafficSimulationConfiguration.h"
#include "Traffic.h"
#include "TrafficCongestionVehicleModel.h"
#include <string>

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class TrafficCongestionVehicleFactory
        {
        private:
            std::string m_vehicleModelSuffix;
            Eegeo::Traffic::Config::TrafficSimulationConfiguration m_trafficConfig;

        public:
            TrafficCongestionVehicleFactory(Traffic::Config::TrafficSimulationConfiguration trafficConfig);

            TrafficCongestionVehicleModel* Create(
                    VehicleDirection::DirectionValues vehicleDirection,
                    int segmentIndex,
                    float currentSegmentDistance,
                    float speedMultiplier);

            void HandleStateChanged(const TrafficCongestionStateData& data);
            void HandleThemeChanged(const TrafficCongestionThemeData& data);
        };
    }
}