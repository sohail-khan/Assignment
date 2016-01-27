// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Collision
    {
        class IRayPicker
        {
        public:
            virtual bool TryGetRayIntersection(const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection, Eegeo::dv3& out_ecefIntersectionPoint, double& out_param) = 0;
        };
    }
}
