// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Terrain.h"

namespace Eegeo
{
    namespace Streaming
    {
        class ResourceCeilingProvider : public Eegeo::NonCopyable
        {
        public:
            ResourceCeilingProvider(const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider);
            
            float GetApproximateResourceCeilingAltitude() const;
            float GetApproximateResourceFloorAltitude() const;
        private:
            const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
        };
    }
}
