// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "Types.h"
#include "CollisionSubMesh.h"

namespace Eegeo
{
    namespace Collision
    {
        class CollisionSubMeshBuilder : public Eegeo::NonCopyable
        {
        public:
            CollisionSubMesh BuildFrom(const CollisionBvh& collisionBvh, int meshIndex);
        };
    }
}