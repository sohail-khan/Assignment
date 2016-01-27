// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "CollisionGroup.h"

#include <string>

namespace Eegeo
{
    namespace Collision
    {
        struct RayCasterResult
        {
            RayCasterResult()
            : intersectionPointEcef(dv3::Zero())
            , meshOriginEcef(dv3::Zero())
            , triangleVertex0(v3::Zero())
            , triangleVertex1(v3::Zero())
            , triangleVertex2(v3::Zero())
            , triangleNormal(v3::Zero())
            , intersectionParam(0.0)
            , collisionGroup(CollisionGroup::Default)
            , collisionMaterialIndex(0)
            , pCollisionBvh(NULL)
            , intersects(false)
            {}
            
            dv3 intersectionPointEcef;
            dv3 meshOriginEcef;
            v3 triangleVertex0;
            v3 triangleVertex1;
            v3 triangleVertex2;
            v3 triangleNormal;
            double intersectionParam;
            CollisionGroup::Type collisionGroup;
            int collisionMaterialIndex;
            const CollisionBvh* pCollisionBvh;
            bool intersects;
        };
    }
}