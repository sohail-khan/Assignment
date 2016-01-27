// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include "Rendering.h"
#include "Roads.h"
#include "Navigation.h"
#include "Collision.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class TransportModelModule : protected Eegeo::NonCopyable
                {
                public:
                    TransportModelModule(const bool showLinkManagerDebugLog);
                    ~TransportModelModule();
                    static TransportModelModule* Create();
                    
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& GetRoadsSceneElementRepository() const;
                    Rendering::Scene::SceneElementRepository<Resources::Roads::RoadNamesRenderable>& GetRoadNamesSceneElementRepository() const;
                    
                    Resources::Roads::Navigation::NavigationGraphRepository& GetRoadNavigationGraphRepository() const;
                    Resources::Roads::Navigation::NavigationGraphBuilder& GetRoadNavigationGraphBuilder() const;
                    
                    Resources::Roads::Navigation::NavigationGraphRepository& GetRailNavigationGraphRepository() const;
                    Resources::Roads::Navigation::NavigationGraphBuilder& GetRailNavigationGraphBuilder() const;
                    
                    Resources::Roads::Navigation::NavigationGraphRepository& GetTramNavigationGraphRepository() const;
                    Resources::Roads::Navigation::NavigationGraphBuilder& GetTramNavigationGraphBuilder() const;
                    
                    Collision::CollisionMeshResourceRepository& GetRoadsCollisionMeshResourceRepository() const;
                    Collision::CollisionMeshResourceRepository& GetRailCollisionMeshResourceRepository() const;
                    Collision::CollisionMeshResourceRepository& GetTramlinesCollisionMeshResourceRepository() const;
                    
                private:
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>* m_pRoadsSceneElementRepository;
                    Rendering::Scene::SceneElementRepository<Resources::Roads::RoadNamesRenderable>* m_pRoadNamesSceneElementRepository;
                    
                    Resources::Roads::Navigation::NavigationGraphRepository* m_pRoadNavGraphRepository;
                    Resources::Roads::Navigation::NavigationGraphLinkManager* m_pRoadNavGraphLinkManager;
                    
                    Resources::Roads::Navigation::NavigationGraphRepository* m_pRailNavGraphRepository;
                    Resources::Roads::Navigation::NavigationGraphLinkManager* m_pRailNavGraphLinkManager;
                    
                    Resources::Roads::Navigation::NavigationGraphRepository* m_pTramNavGraphRepository;
                    Resources::Roads::Navigation::NavigationGraphLinkManager* m_pTramNavGraphLinkManager;
                    
                    Eegeo::Collision::CollisionMeshResourceRepository* m_pRoadsCollisionMeshResourceRepository;
                    Eegeo::Collision::CollisionMeshResourceRepository* m_pRailCollisionMeshResourceRepository;
                    Eegeo::Collision::CollisionMeshResourceRepository* m_pTramlinesCollisionMeshResourceRepository;
                };
            }
        }
    }            
}