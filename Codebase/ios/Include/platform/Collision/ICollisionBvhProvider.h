// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "ICallback.h"

#include <vector>

namespace Eegeo
{
    namespace Collision
    {
        class ICollisionBvhProvider
        {
        public:
            virtual ~ICollisionBvhProvider() { };
            
            virtual size_t CountCollisionBvhsForGroups(u32 collisionGroupsMask) const = 0;
            
            virtual size_t CopyCollisionBvhsForGroups(u32 collisionGroupsMask, const CollisionBvh** pCollisionBvhBufer, size_t maxBufferElements) const = 0;
            
            typedef Eegeo::Helpers::ICallback0 INotifyChangedCallback;
            virtual void RegisterObserver(INotifyChangedCallback& callback) = 0;
            
            virtual void UnregisterObserver(INotifyChangedCallback& callback) = 0;
        };
    }

}
