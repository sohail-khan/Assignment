// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Collision.h"
#include "Interiors.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class InteriorsModelModule : private Eegeo::NonCopyable
                {
                public:
                    static InteriorsModelModule* Create();
                    
                    InteriorsModelModule();
                    virtual ~InteriorsModelModule();
                    
                    virtual void Update();
                    
                    virtual Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& GetInteriorsSceneElementRepository() const;
                    virtual Eegeo::Collision::CollisionMeshResourceRepository& GetInteriorsCollisionMeshResourceRepository() const;
                    virtual Eegeo::Collision::CollisionMeshResourceRepository& GetInteriorsHighlightsCollisionMeshResourceRepository() const;
                    virtual Resources::Interiors::InteriorsModelRepository& GetInteriorsModelRepository() const;
                    virtual Resources::Interiors::InteriorsInstanceRepository& GetInteriorsInstanceRepository() const;
                    virtual Resources::Interiors::Entities::InteriorsEntitiesRepository& GetInteriorsEntitiesRepository() const;
                    virtual Resources::Interiors::Markers::InteriorMarkerModelRepository& GetInteriorMarkerModelRepository() const;
                    virtual Resources::Interiors::InteriorsCellResourceObserver& GetInteriorsCellResourceObserver() const;
                    
                private:
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>* m_pInteriorsSceneElementRepository;
                    Resources::Interiors::InteriorsModelRepository* m_pInteriorsModelRepository;
                    Resources::Interiors::InteriorsInstanceRepository* m_pInteriorsInstanceRepository;
                    Resources::Interiors::InteriorsModelEvictor* m_pInteriorsModelEvictor;
                    Eegeo::Collision::CollisionMeshResourceRepository* m_pInteriorsCollisionMeshResourceRepository;
                     Eegeo::Collision::CollisionMeshResourceRepository* m_pInteriorsHighlightCollisionMeshResourceRepository;
                    
                    Resources::Interiors::Entities::InteriorsEntitiesRepository* m_pInteriorsEntitiesRepository;
                    Resources::Interiors::Markers::InteriorMarkerModelRepository* m_pInteriorMarkerModelRepository;
                    Resources::Interiors::InteriorsCellResourceObserver* m_pInteriorsCellResourceObserver;
                };
            }
        }
    }
}