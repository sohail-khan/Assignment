// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuiltResourceWithKey.h"
#include "TerrainHeightLookup.h"
#include "Types.h"
#include "Terrain.h"
#include "VectorMath.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Raster
            {
                class RasterTerrainHeightLookup : public BuiltResourceWithKey, public ITerrainHeightLookup, protected Eegeo::NonCopyable
                {
                    Eegeo::Resources::Terrain::Heights::TerrainHeightRepository *m_pTerrainHeightRepository;
                    Eegeo::dv3 m_ecefCellCenter;
                    std::vector<float> m_heights;
                    float m_maxHeight;
                    float m_minHeight;
                
                public:
                    
                    RasterTerrainHeightLookup(Eegeo::Resources::Terrain::Heights::TerrainHeightRepository *pTerrainHeightRepository,
                                              const Streaming::MortonKey& key,
                                              Eegeo::dv3 ecefCellCenter,
                                              std::vector<float> heights);

                    ~RasterTerrainHeightLookup();
                    
                    bool TryGetHeight(Eegeo::dv3 ecefPoint, float &height) const;
                    bool TryGetHeight(Eegeo::dv3 ecefPoint, Streaming::MortonKey key, float &height) const;

                    float GetMaxHeight() const { return m_maxHeight; }
                    float GetMinHeight() const { return m_minHeight; }
                    
                    void Unload();
                    void RemovedFromSceneGraph();
                    void AddedToSceneGraph();
                    
                    const Eegeo::Streaming::MortonKey& GetMortonKey() const;
                };
            }
        }
    }
}
