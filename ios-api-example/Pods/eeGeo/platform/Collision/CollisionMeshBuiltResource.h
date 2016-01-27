// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "BuiltResourceWithKey.h"
#include "ICollisionMeshResource.h"

namespace Eegeo
{
    namespace Collision
    {
        class CollisionMeshBuiltResource : public Resources::BuiltResourceWithKey, public Eegeo::Collision::ICollisionMeshResource, public Eegeo::NonCopyable
        {
        public:
            
            CollisionMeshBuiltResource(Eegeo::Collision::CollisionMeshResourceRepository& collisionMeshResourceRepository,
                                       const Streaming::MortonKey& key,
                                       const Eegeo::Collision::CollisionBvh* pCollisionBvh);
            virtual ~CollisionMeshBuiltResource();
            
            // IBuiltResource
            virtual void Unload();
            virtual void RemovedFromSceneGraph();
            virtual void AddedToSceneGraph();
            
            // ICollisionMeshResource
            virtual const Eegeo::Collision::CollisionBvh& GetCollisionBvh() const;
            
        private:
            Eegeo::Collision::CollisionMeshResourceRepository& m_collisionMeshResourceRepository;
            const Eegeo::Collision::CollisionBvh* m_pCollisionBvh;
        };
    }
}

