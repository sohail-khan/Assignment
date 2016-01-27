// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Traffic.h"
#include "Random.h"
#include "PlaneSimulationConfig.h"
#include "TrafficSimulationConfiguration.h"
#include "Camera.h"
#include "Streaming.h"
#include "Terrain.h"
#include "Rendering.h"
#include "Helpers.h"
#include <string>

namespace Eegeo
{
    namespace Traffic
    {
        class PlaneSimulation : protected Eegeo::NonCopyable
        {
            
        public:
            PlaneSimulation(const Config::TrafficSimulationConfiguration& config,
                            const Config::PlaneSimulationConfig& planeSimulationConfig,
                            VehicleRenderablesModel* renderablesModel,
                            Random& randomGenerator,
                            Streaming::CameraFrustumStreamingVolume& streamingVolume,
                            Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                            const Rendering::EnvironmentFlatteningService& environmentFlatteningService);
            
            ~PlaneSimulation();
            
            VehicleRenderablesModel& GetRenderablesModel() const { return *m_pVehicleRenderablesModel; }
            
            void Update(float deltaSeconds, const Camera::RenderCamera& renderCamera);
            
            void ApplyVehicleSuffixChange(const std::string &suffix);
            void UpdateConfig(const Config::TrafficSimulationConfiguration& newConfig);
            
            void SetPlaneSimulationConfig(const Config::PlaneSimulationConfig& planeSimulationConfig) { m_planeSimulationConfig = planeSimulationConfig; }
            void SetEnabled(bool value);
            
            static Config::PlaneSimulationConfig CreateDefaultPlaneSimulationConfig();
            
        private:
            PlaneVehicle* TryCreateNewPlane(const Camera::RenderCamera& renderCamera);
            void RemoveAllPlanesInScene();

            bool m_enabled;
            VehicleRenderablesModel* m_pVehicleRenderablesModel;
            Streaming::CameraFrustumStreamingVolume& m_streamingVolume; 
            Random& m_randomGenerator;
            Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
            Config::TrafficSimulationConfiguration m_config;
            const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
            float m_secondsToNextTerrainQuery;

            PlaneVehicle* m_currentPlane;
            std::string m_modelNodeNameSuffix;

            Config::PlaneSimulationConfig m_planeSimulationConfig;
            Helpers::RouletteWheelSelector* m_pRouletteWheelSelector;
        };
    }
}
