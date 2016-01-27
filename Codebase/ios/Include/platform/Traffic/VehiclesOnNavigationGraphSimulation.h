// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "Traffic.h"
#include "Streaming.h"
#include "NavigationGraphAddedCallback.h"
#include "NavigationGraphRemovalCallback.h"
#include "TrafficSimulationAltitudeSpeedConfiguration.h"
#include "Terrain.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Traffic
    {
        class VehiclesOnNavigationGraphSimulation : protected Eegeo::NonCopyable
        {
        public:
            VehiclesOnNavigationGraphSimulation(
                    Traffic::Config::TrafficSimulationAltitudeSpeedConfiguration altitudeSpeedConfiguration,
                    Resources::Roads::Navigation::NavigationGraphRepository& navGraphRepository,
                    const Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                    IVehicleFactory* pVehicleFactory,
                    TrafficSimulationCellsModel* pCellsModel,
                    VehicleRenderablesModel* pRenderablesModel,
                    Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                    const Rendering::EnvironmentFlatteningService& environmentFlatteningService);

            ~VehiclesOnNavigationGraphSimulation();
            
            VehicleRenderablesModel& GetRenderablesModel() const { return *m_pVehicleRenderablesModel; }
            
            bool Enabled() const { return m_enabled; }
            void SetEnabled(bool enabled) { m_enabled = enabled; }
            
            void Update(float deltaTimeSeconds, const dv3& cameraEcefLocation, const dv3& ecefInterestPoint);
            
            void UpdateConfig(const Config::TrafficSimulationConfiguration& roadConfig);
            void UpdateAltitudeSpeedConfig(Config::TrafficSimulationAltitudeSpeedConfiguration config);
            void ApplyVehicleSuffixChange(const std::string &suffix);

            void Reset();
            
        private:
            Traffic::Config::TrafficSimulationAltitudeSpeedConfiguration m_trafficSimulationAltitudeSpeedConfig;
            Resources::Roads::Navigation::NavigationGraphRepository& m_graphRepository;
            const Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
            TrafficSimulationCellsModel* m_pCellsModel;
            IVehicleFactory* m_pVehicleFactory;
            VehicleRenderablesModel* m_pVehicleRenderablesModel;
            bool m_enabled;
            Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
            const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
            
            void UpdateCells(float deltaSeconds, const dv3& cameraEcefLocation, const dv3& ecefInterestPoint);
            void CreateAndAddSimulationCell(const Resources::Roads::Navigation::NavigationGraph& navGraph);
            void RemoveSimulationCellForKey(const Streaming::MortonKey& key);
            
            void NavigationGraphAdded(const Resources::Roads::Navigation::NavigationGraph& navGraph);
            void NavigationGraphRemoved(const Resources::Roads::Navigation::NavigationGraph& navGraph);
            
            Resources::Roads::Navigation::TNavigationGraphAddedCallback<VehiclesOnNavigationGraphSimulation> m_graphAdditionFunctor;
            Resources::Roads::Navigation::TNavigationGraphRemovalCallback<VehiclesOnNavigationGraphSimulation> m_graphRemovalFunctor;
        };
    }
}
