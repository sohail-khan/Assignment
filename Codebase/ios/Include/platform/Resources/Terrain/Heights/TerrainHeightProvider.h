// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Terrain.h"
#include "VectorMathDecl.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Heights
            {
                class TerrainHeightProvider : protected Eegeo::NonCopyable
                {
                private:
                    TerrainHeightRepository& m_heightRepository;
                    bool m_debugLog;
                    static const int MAX_TERRAIN_DEPTH;
                public:
                    TerrainHeightProvider(TerrainHeightRepository& heightRepository);
                    
                    virtual ~TerrainHeightProvider();
                    
                    bool TryGetHeight(const Eegeo::dv3& ecefPosition, int minLevel, float& out_terrainHeight) const;
                    
                    bool TryGetHeight(const Eegeo::dv3& ecefPosition, const Streaming::MortonKey& key, float& out_terrainHeight) const;
                    
                    bool TryGetHeight(const Eegeo::dv3& ecefPosition,
                                      int minLevel,
                                      int previousQueryTerminationLevel,
                                      float previousQueryTerrainHeight,
                                      int& out_queryTerminationLevel,
                                      float& out_terrainHeight) const;
                    
                    bool HasHeightsForKey(Streaming::MortonKey key) const;
                    
                    float GetMaxHeight() const;
                    float GetMinHeight() const;
                    
                    void SetDebugLog(bool enabled) { m_debugLog = enabled; }
                };
            }
        }
	}
}