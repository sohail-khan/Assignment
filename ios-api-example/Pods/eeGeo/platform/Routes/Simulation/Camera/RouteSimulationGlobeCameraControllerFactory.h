// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Terrain.h"
#include "Collision.h"
#include "Rendering.h"
#include "Streaming.h"
#include "GlobeCamera.h"
#include "Routes.h"
#include "RouteSimulationGlobeCameraControllerConfig.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            namespace Camera
            {
                class RouteSimulationGlobeCameraControllerFactory : Eegeo::NonCopyable
                {
                public:
                    RouteSimulationGlobeCameraControllerFactory(const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                                                const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                                const Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                                                                const Collision::ICollisionBvhProvider& collisionMeshResourceProvider);
                    
                    RouteSimulationGlobeCameraController* Create(bool useLowLodSettings,
                                                                 const Eegeo::Rendering::ScreenProperties& screenProperties) const;
                    
                    RouteSimulationGlobeCameraController* Create(bool useLowLodSettings,
                                                                 Eegeo::Camera::GlobeCamera::GlobeCameraTouchControllerConfiguration touchConfiguration,
                                                                 RouteSimulationGlobeCameraControllerConfig routeSimCameraConfig,
                                                                 const Eegeo::Rendering::ScreenProperties& screenProperties) const;
                private:
                    const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                    const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                    const Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
                    const Collision::ICollisionBvhProvider& m_collisionMeshResourceProvider;
                };
            }
        }
    }
}