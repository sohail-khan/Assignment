// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Camera.h"
#include "Location.h"
#include "Rendering.h"
#include "Traffic.h"
#include "Navigation.h"
#include "Random.h"
#include "Streaming.h"
#include "Terrain.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Traffic
    {
        class TrafficSimulationFactory
        {
        public:
            
            TrafficSimulationFactory(Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                     const Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                                     Random& randomGenerator,
                                     Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvder)
            : m_environmentFlatteningService(environmentFlatteningService)
            , m_resourceCeilingProvider(resourceCeilingProvider)
            , m_randomGenerator(randomGenerator)
            , m_terrainHeightProvider(terrainHeightProvder)
            {
                
            }
            
            VehiclesOnNavigationGraphSimulation* CreateRoadTrafficSimulation(
                    const Traffic::Config::TrafficSimulationConfiguration& config,
                    const Config::TrafficSimulationAltitudeSpeedConfiguration& altitudeSpeedConfig,
                    Resources::Roads::Navigation::NavigationGraphRepository& navGraphRepository);
            
            VehiclesOnNavigationGraphSimulation* CreateRailTrafficSimulation(
                    const Traffic::Config::TrafficSimulationConfiguration& config,
                    const Config::TrafficSimulationAltitudeSpeedConfiguration& altitudeSpeedConfig,
                    Resources::Roads::Navigation::NavigationGraphRepository& navGraphRepository);
            
            PlaneSimulation* CreatePlaneSimulation(const Config::TrafficSimulationConfiguration& config,
                                                   const Config::PlaneSimulationConfig& planeSimulationConfig,
                                                   Streaming::CameraFrustumStreamingVolume& streamingVolume,
                                                   Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider);
        private:
            
            Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
            const Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
            Random& m_randomGenerator;
            Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
            
            VehiclesOnNavigationGraphSimulation* CreateNavGraphTrafficSimulation(
                    Resources::Roads::Navigation::NavigationGraphRepository& navGraphRepository,
                    IVehicleFactory* pVehicleFactory,
                    TrafficSimulationCellsModel* pCellsModel,
                    const Config::TrafficSimulationConfiguration& config,
                    const Config::TrafficSimulationAltitudeSpeedConfiguration& altitudeSpeedConfig);
        };
    }
}