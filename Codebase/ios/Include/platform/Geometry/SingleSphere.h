// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    namespace Geometry
    {
        struct SingleSphere
        {
            Eegeo::v3 centre;
            float radius;
        };
        
        SingleSphere BoundingSphereFromCentreAndPoints(const v3& centre, const std::vector<v3>& points);
        
        bool SphereContainsPoint(const SingleSphere& sphere, const v3& point);

        void CalculateSphereSuperset(SingleSphere& sphereA,
                                     SingleSphere& sphereB,
                                     SingleSphere& out_sphere);
    }
}
