// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Terrain.h"
#include "Collision.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class TerrainModelModule : protected Eegeo::NonCopyable
                {
                public:
                    TerrainModelModule();
                    ~TerrainModelModule();
                    static TerrainModelModule* Create();
                    
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& GetLcmSceneElementRepository() const;
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::WorldMeshRenderable>& GetRasterTerrainSceneElementRepository() const;
                    Resources::Terrain::Heights::TerrainHeightRepository& GetTerrainHeightRepository() const;
                    Eegeo::Collision::CollisionMeshResourceRepository& GetTerrainCollisionMeshResourceRepository() const;
                    Eegeo::Collision::CollisionMeshResourceRepository& GetTreesCollisionMeshResourceRepository() const;
                    Resources::Terrain::Heights::TerrainHeightProvider& GetTerrainHeightProvider() const;
                    
                    //! \deprecated
                    Eegeo::Collision::CollisionMeshResourceRepository& GetCollisionMeshResourceRepository() const { return GetTerrainCollisionMeshResourceRepository(); }
                    
                private:
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>* m_pLcmSceneElementRepository;
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::WorldMeshRenderable>* m_pRasterTerrainSceneElementRepository;
                    Resources::Terrain::Heights::TerrainHeightRepository* m_pTerrainHeightRepository;
                    Eegeo::Collision::CollisionMeshResourceRepository* m_pTerrainCollisionMeshResourceRepository;
                    Eegeo::Collision::CollisionMeshResourceRepository* m_pTreesCollisionMeshResourceRepository;
                    Resources::Terrain::Heights::TerrainHeightProvider* m_pTerrainHeightProvider;
                };
            }
        }
    }
}