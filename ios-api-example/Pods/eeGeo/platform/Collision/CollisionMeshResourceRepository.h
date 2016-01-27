// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "CollisionGroup.h"
#include "Types.h"
#include "ICollisionBvhProvider.h"
#include "MortonKey.h"
#include "ICallback.h"
#include "CallbackCollection.h"

#include <vector>
#include <map>

namespace Eegeo
{
    namespace Collision
    {
        class CollisionMeshResourceRepository : public ICollisionBvhProvider, protected Eegeo::NonCopyable
        {
        public:
            CollisionMeshResourceRepository(CollisionGroup::Type collisionGroup);
            
            virtual void Add(Eegeo::Streaming::MortonKey key, const ICollisionMeshResource& collisionMeshResource);
            
            virtual void Remove(Eegeo::Streaming::MortonKey key, const ICollisionMeshResource& collisionMeshResource);
            
            virtual size_t CountCollisionBvhsForGroups(u32 collisionGroupsMask) const;
            
            virtual size_t CopyCollisionBvhsForGroups(u32 collisionGroupsMask, const CollisionBvh** pCollisionBvhBufer, size_t maxBufferElements) const;
            
            virtual void RegisterObserver(INotifyChangedCallback& callback);
            
            virtual void UnregisterObserver(INotifyChangedCallback& callback);
            
        private:
            const CollisionGroup::Type m_collisionGroup;
            
            typedef std::map<const ICollisionMeshResource*, Eegeo::Streaming::MortonKey> TMapType;

            TMapType m_resources;
            
            Eegeo::Helpers::CallbackCollection0 m_changedCallbacks;
        };
        
 
    }
}