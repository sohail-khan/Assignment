// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "GlobeCamera.h"
#include "Terrain.h"
#include "Rendering.h"
#include "Streaming.h"
#include "Types.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            class GlobeCameraControllerFactory : private NonCopyable
            {
            public:
                
                GlobeCameraControllerFactory(const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                            const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                            const Streaming::ResourceCeilingProvider& resourceCeilingProvider);
                
                GlobeCameraTouchController* CreateTouchController(const GlobeCameraTouchControllerConfiguration& config,
                                                                  const Eegeo::Rendering::ScreenProperties& screenProperties);
                
                GlobeCameraController* CreateCameraController(const GlobeCameraControllerConfiguration& config,
                                                              const GlobeCameraTouchController& touchController,
                                                              const Eegeo::Rendering::ScreenProperties& screenProperties);
                
                
            private:
                
                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                const Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
            };
        }
    }
}