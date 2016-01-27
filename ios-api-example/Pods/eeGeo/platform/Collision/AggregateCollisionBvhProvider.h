// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ICollisionBvhProvider.h"
#include "Types.h"
#include "Collision.h"
#include "ICallback.h"
#include "CallbackCollection.h"

#include <vector>

namespace Eegeo
{
    namespace Collision
    {
        class AggregateCollisionBvhProvider : public ICollisionBvhProvider, public Eegeo::NonCopyable
        {
        public:
            AggregateCollisionBvhProvider();
            
            virtual ~AggregateCollisionBvhProvider() { }
            
            virtual size_t CountCollisionBvhsForGroups(u32 collisionGroupsMask) const;
            
            virtual size_t CopyCollisionBvhsForGroups(u32 collisionGroupsMask, const CollisionBvh** pCollisionBvhBufer, size_t maxBufferElements) const;
            
            virtual void RegisterObserver(INotifyChangedCallback& callback);
            
            virtual void UnregisterObserver(INotifyChangedCallback& callback);
            
            virtual void AddProvider(ICollisionBvhProvider& provider);
            virtual void RemoveProvider(ICollisionBvhProvider& provider);
            
            virtual void SendNotifications();
            
            virtual void HandleProviderChanged();
        private:
            std::vector<const ICollisionBvhProvider*> m_providers;
            
            Helpers::TCallback0<AggregateCollisionBvhProvider> m_handleProviderChanged;
            Eegeo::Helpers::CallbackCollection0 m_changedCallbacks;
            bool m_providersChanged;
        };
        

    }
    
}
