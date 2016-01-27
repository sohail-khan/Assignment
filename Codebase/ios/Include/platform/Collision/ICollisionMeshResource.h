// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"

namespace Eegeo
{
    namespace Collision
    {
        class ICollisionMeshResource
        {
        public:
            virtual const Eegeo::Collision::CollisionBvh& GetCollisionBvh() const = 0;
        };
    }
}
