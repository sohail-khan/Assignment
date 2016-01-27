// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "MortonKey.h"
#include "Terrain.h"
#include <vector>
#include <map>

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Heights
            {
                class TerrainHeightRepository : protected Eegeo::NonCopyable
                {
                private:
                    std::map<Eegeo::Streaming::MortonKey, ITerrainHeightLookup*, Eegeo::Streaming::MortonKeyCompare> m_resources;
                    
                    void CallAddedCallbacks(const ITerrainHeightLookup& terrainHeightLookup);
                    void CallRemovalCallbacks(const ITerrainHeightLookup& terrainHeightLookup);
                    
                    std::vector<ITerrainHeightsCallback*> m_addedCallbacks;
                    std::vector<ITerrainHeightsCallback*> m_removalCallbacks;
                    
                public:
                    
                    void AddHeights(Eegeo::Streaming::MortonKey key, ITerrainHeightLookup* heights);

                    void RemoveHeights(Eegeo::Streaming::MortonKey key);
                    
                    ITerrainHeightLookup* GetHeights(Eegeo::Streaming::MortonKey key) const;
                    
                    float GetMaxHeight() const;
                    float GetMinHeight() const;
                    
                    void RegisterAddedCallback(ITerrainHeightsCallback* callback);
                    void UnregisterAddedCallback(ITerrainHeightsCallback* callback);
                    
                    void RegisterRemovalCallback(ITerrainHeightsCallback* callback);
                    void UnregisterRemovalCallback(ITerrainHeightsCallback* callback);
                };
            }
        }
    }
}
