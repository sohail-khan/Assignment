// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "CollisionGroup.h"
#include "RayCasterResult.h"
#include "Rendering.h"


namespace Eegeo
{
    namespace Collision
    {
        class IRayCaster
        {
        public:
            virtual ~IRayCaster(){};
            
            virtual RayCasterResult CastRay(const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection, u32 collidableGroupsMask) = 0;
        };
    }
}