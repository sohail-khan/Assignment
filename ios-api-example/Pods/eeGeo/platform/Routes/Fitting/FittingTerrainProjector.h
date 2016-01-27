// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "VectorMath.h"
#include "Terrain.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class FittingTerrainProjector : Eegeo::NonCopyable
            {
            private:
                const Streaming::MortonKey& m_key;
                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                dv3 m_ecefOrigin;
            public:
                FittingTerrainProjector(const Streaming::MortonKey &key, const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider);
                
                bool TryGetPositionOnTerrain(const v3& localPosition, v3& out_localPositionOnTerrain) const;
            };
        }
    }
}
