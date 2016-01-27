// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MathFunc.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Geometry
    {
        class DoublePlane
        {
        public:
            dv3 Normal;
            double Distance;
            
            
            double SignedDistanceToPoint(const dv3& point) const
            {
                return dv3::Dot(Normal, point) - Distance;
            }
            
            bool IsOnPositiveSide(const dv3& point) const
            {
                return SignedDistanceToPoint(point) >= 0.0;
            }
            
            
            static DoublePlane CreateFromPoints(const dv3& p0, const dv3& p1, const dv3& p2);
            
            static DoublePlane CreateFromNormalAndPoint(const dv3& normal, const dv3& pointOnPlane);
            
            static DoublePlane Zero();
        };
    }
}
