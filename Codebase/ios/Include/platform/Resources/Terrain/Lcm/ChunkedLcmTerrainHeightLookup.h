// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ChunkedFileFormat.h"
#include "Collision.h"
#include "BuiltResourceWithKey.h"
#include "TerrainHeightLookup.h"
#include "ICollisionMeshResource.h"
#include "Types.h"
#include "VectorMath.h"
#include "Terrain.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace lcm
            {
                class ChunkedLcmTerrainHeightLookup : public BuiltResourceWithKey, public ITerrainHeightLookup, public Eegeo::Collision::ICollisionMeshResource, protected Eegeo::NonCopyable
                {
                public:
                    
                    ChunkedLcmTerrainHeightLookup(Eegeo::Resources::Terrain::Heights::TerrainHeightRepository *pTerrainHeightRepository,
                                                  Eegeo::Collision::CollisionMeshResourceRepository *pCollisionMeshResourceRepository,
                                                  const Streaming::MortonKey& key,
                                                  const Eegeo::dv3& ecefCellCenter,
                                                  Eegeo::Collision::CollisionBvh* pCollisionBvh,
                                                  const bool needsLegacyTerrainCollisionFixup);
                    ~ChunkedLcmTerrainHeightLookup();
                    
                    bool TryGetHeight(Eegeo::dv3 ecefPoint, float& height) const;
                    bool TryGetHeight(Eegeo::dv3 ecefPoint, Streaming::MortonKey key, float& height) const;
                    
                    float GetMaxHeight() const;
                    float GetMinHeight() const;
                    
                    void Unload();
                    void RemovedFromSceneGraph();
                    void AddedToSceneGraph();
                    
                    const Eegeo::Streaming::MortonKey& GetMortonKey() const;
                    
                    virtual const Eegeo::Collision::CollisionBvh& GetCollisionBvh() const;
                    
                private:
                    
                    bool TryGetHeightFromCulledHeightMesh(Eegeo::dv3 ecefPoint, Streaming::MortonKey key, float& height) const;
                    bool TryGetHeightFromInvalidCulledHeightMesh(Eegeo::dv3 ecefPoint, float& height) const;
                    
                    
                    Eegeo::Resources::Terrain::Heights::TerrainHeightRepository *m_pTerrainHeightRepository;
                    Eegeo::Collision::CollisionMeshResourceRepository *m_pCollisionMeshResourceRepository;
                    
                    Eegeo::dv3 m_ecefCellCenter;
                    
                    bool m_needsLegacyTerrainCollisionFixup;
                    
                    Eegeo::Collision::CollisionBvh* m_pCollisionBvh;
                };
            }
        }
    }
}
