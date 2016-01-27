// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Geometry
    {
        struct Line2
        {
            v2 point;
            v2 dir;

            Line2(const v2 linePoint, const v2 lineDir) : point(linePoint), dir(lineDir)
            {
                dir = lineDir.Norm();
            }
        };
    }
}

