// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GlobeCamera.h"
#include "Terrain.h"
#include "Streaming.h"
#include "Rendering.h"
#include "Location.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            //! Factory class for constructing GpsGlobeCameraController instances
            class GpsGlobeCameraControllerFactory
            {
            public:
                GpsGlobeCameraControllerFactory(const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                                const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                const Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                                                Location::NavigationService& navigationService)
                : m_terrainHeightProvider(terrainHeightProvider)
                , m_environmentFlatteningService(environmentFlatteningService)
                , m_resourceCeilingProvider(resourceCeilingProvider)
                , m_navigationService(navigationService)
                {
                }
                
                //! \return a GpsGlobeCameraController instance with default configuration
                GpsGlobeCameraController* Create(bool useLowLodSettings,
                                                 const Eegeo::Rendering::ScreenProperties& screenProperties);
                
                //! \return a GpsGlobeCameraController instance created with specified configuration structures
                GpsGlobeCameraController* Create(const GpsGlobeCameraComponentConfiguration& gpsControllerConfig,
                                                 const GlobeCameraTouchControllerConfiguration& touchControllerConfig,
                                                 const GlobeCameraControllerConfiguration& globeCameraConfig,
                                                 const Eegeo::Rendering::ScreenProperties& screenProperties);

            private:
                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                const Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
                Location::NavigationService& m_navigationService;
            };
        }
    }
}