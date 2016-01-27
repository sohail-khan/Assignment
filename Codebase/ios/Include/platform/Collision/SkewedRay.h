// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Collision
    {
        struct SkewedRay
        {
            v3 Origin;
            v3 Direction;
            float SkewedParamScale;
            
            SkewedRay()
            : Origin(v3::Zero())
            , Direction(v3::Zero())
            , SkewedParamScale(0.f)
            {}
            
            SkewedRay(const v3& origin, const v3& direction, float skewedParamScale)
            : Origin(origin)
            , Direction(direction)
            , SkewedParamScale(skewedParamScale)
            {}
        };
    }
}