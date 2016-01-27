// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Geometry
    {
        inline void CatmullRomInterpolationInPlace(const double t, const dv3& p0, const dv3& p1, const dv3& p2, const dv3& p3, dv3& out_result)
        {
            double t2 = t*t;
            double t3 = t*t*t;
            
            out_result = 0.5 * ((2.0 * p1) +
                                (-p0 + p2) * t +
                                (2.0*p0 - 5.0*p1 + 4.0*p2 - p3) * t2 +
                                (-p0 + 3.0*p1 - 3.0*p2 + p3) * t3);
        }
    }
}