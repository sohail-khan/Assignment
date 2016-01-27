// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "VectorMathDecl.h"
#include "TrafficCongestion.h"
#include "TrafficCongestionVehicleModel.h"
#include "TrafficCongestionConfig.h"
#include <map>

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class TrafficCongestionSimulationCell : Eegeo::NonCopyable
        {
        public:
            typedef std::map<int, TrafficCongestionVehicles *> TRoadIndexToVehicles;

            TrafficCongestionSimulationCell(
                    const TrafficCongestionConfig& config,
                    Eegeo::Resources::Roads::Navigation::NavigationGraph& navGraph,
                    TrafficCongestionVehicleFactory& vehicleFactory
            );
            virtual ~TrafficCongestionSimulationCell();

            void AddRoadCongestionFor(int roadIndex, CongestionLevel::CongestionLevelValues severity);
            void Update(float dt, Traffic::VehicleRenderablesModel& vehicleRenderablesModel, const dv3& cameraEcefLocation);
            void HandleStateChanged(const TrafficCongestionStateData& state);
            void HandleThemeChanged(const TrafficCongestionThemeData& data);

            void Clear();
            void UpdateFromModel(const TrafficCongestionModelCell& model);

        private:
            void AddVehicle(int roadIndex, const CongestionSettings& settings, bool addFromTo, bool addToFrom);
            void AddVehicleAt(
                    VehicleDirection::DirectionValues vehicleDirection,
                    int roadIndex,
                    int segmentIndex,
                    float distanceTravelled,
                    float speedMultiplier);

            Eegeo::Resources::Roads::Navigation::NavigationGraph& m_navGraph;
            const TrafficCongestionConfig& m_config;
            TrafficCongestionVehicleFactory& m_vehicleFactory;
            TRoadIndexToVehicles m_roadIndexToVehicleModels;
        };
    }
}
