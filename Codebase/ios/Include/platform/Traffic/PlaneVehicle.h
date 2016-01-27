// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Traffic.h"
#include "Camera.h"
#include "Random.h"
#include "Streaming.h"
#include "TrafficSimulationConfiguration.h"
#include "Helpers.h"
#include <string>

namespace Eegeo
{
    namespace Traffic
    {
        class PlaneVehicle : protected Eegeo::NonCopyable
        {
        private:
            float m_timeOutsideViewVolume;
            std::string m_fullModelNodeName;

            float m_currentHeightAboveTerrain;
            float m_currentTerrainHeight;
            float m_targetTerrainHeight;
            dv3 m_surfacePosition;
            
        public:
            
            dv3 position;
            v3 forward;
            v3 localY;
            const Config::TrafficSimulationVehicleConfiguration config;

            PlaneVehicle(dv3 &startPositionOnSurface,
                         float initialTerrainHeight,
                         float heightAboveTerrain,
                         v3 &forwardDirection,
                         v3 &up,
                         const Config::TrafficSimulationVehicleConfiguration& _vehicleConfig,
                         const std::string & modelNodeNameSuffix);

            void SetModelNodeNameSuffix(const std::string & modelNodeNameSuffix);
            std::string& GetFullModelNodeName();
            
            void SetTerrainHeight(const float terrainHeight);

            void Update(float deltaSeconds, float speedMultiplier, float planeCullingSphereRadius, Streaming::CameraFrustumStreamingVolume& streamingVolume, float currentFlatteningScale);

            bool ShouldDispose(float maxTimeOutsideViewVolumeBeforeDespawn);
            
            static PlaneVehicle * CreateAtHeight(float initialTerrainHeight,
                                                 float heightAboveTerrain,
                                                 const Camera::RenderCamera& renderCamera,
                                                 Random & randomGenerator,
                                                 const Helpers::RouletteWheelSelector& selector,
                                                 const Config::TrafficSimulationConfiguration& config,
                                                 const std::string & modelNameSuffix);
        };
    }
}
