// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "GlobeCamera.h"
#include "VectorMathDecl.h"
#include "Terrain.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            class GlobeCameraTerrainFollower : Eegeo::NonCopyable
            {
            public:
                GlobeCameraTerrainFollower(
                    const Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                    float maxHeightDelta,
                    float smoothingTimeConstant);
                
                void MovePointTowardsTerrainSurface(float deltaSeconds, const dv3& pointEcef, dv3& out_pointEcef) const;
            private:
                float CalculateSmoothedTerrainHeight(float deltaSeconds, float currentTerrainHeight, float targetTerrainHeight) const;
                
                const Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& m_heightLookup;
                const float m_maxHeightDelta;
                const float m_smoothingTimeConstant;
            };
        }
    }
}
