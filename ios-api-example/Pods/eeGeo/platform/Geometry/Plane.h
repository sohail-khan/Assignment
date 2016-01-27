// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MathFunc.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Geometry
    {
        class Plane
        {
        public:
            
            float a, b, c, d;
            
            Plane Norm() const
            {
                float length = 1.f/Eegeo::Math::Sqrtf(a*a + b*b + c*c);
                Plane p;
                
                p.a = a*length;
                p.b = b*length;
                p.c = c*length;
                p.d = d*length;
                
                return p;
            }
            
            
            static Plane CreateFromNormalAndPoint(const v3& normal, const v3& pointOnPlane);
            static Plane Create(const v3& normal, float distanceOriginToPlane);
            
            static Plane Zero();
            
            static Plane Transform(const Plane& plane, const m44& nonScalingTransform);
        };
    }
}
