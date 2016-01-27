// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Collision.h"
#include "LandmarkToRenderableRepository.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class BuildingModelModule : protected Eegeo::NonCopyable
                {
                public:
                    BuildingModelModule();
                    ~BuildingModelModule();
                    static BuildingModelModule* Create();
                    
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& GetBuildingSceneElementRepository() const;
                    
                    Eegeo::Collision::CollisionMeshResourceRepository& GetCollisionMeshResourceRepository() const;
                    
                    Resources::Buildings::LandmarkToRenderableRepository& GetLandmarkToRenderableRepository() const;
                    
                private:
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>* m_pBuildingSceneElementRepository;
                    Eegeo::Collision::CollisionMeshResourceRepository* m_pCollisionMeshResourceRepository;
                    Resources::Buildings::LandmarkToRenderableRepository* m_pLandmarkToRenderableRepository;
                    
                };
            }
        }
    }
}