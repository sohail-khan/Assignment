// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "IntersectionTests.h"

namespace Eegeo
{
    namespace Geometry
    {
        class Sphere
        {
        public:
            Eegeo::dv3 center;
            double radius;
            
            bool IntersectsWithRay(Eegeo::dv3 rayStartPoint, Eegeo::dv3 rayDirection) const
            {
                return IntersectionTests::TestRaySphere(rayStartPoint, rayDirection, center, radius);
            }
            
            bool IntersectsWithSphere(Sphere& sphere)
            {
                return IntersectionTests::TestSphereSphere(this->center, this->radius, sphere.center, sphere.radius);
            }
        };
    }
}
