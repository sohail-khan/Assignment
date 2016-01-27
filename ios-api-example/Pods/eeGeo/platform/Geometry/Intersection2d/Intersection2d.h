// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Line2.h"

namespace Eegeo
{
    namespace Geometry
    {
        int Intersect2dLineSegments(
                const v2& a, const v2& b,
                const v2& c, const v2& d,
                float & outTIntersection, v2& outPointIntersection
        );

        int Intersect2dLines(
                const v2& linePointA, const v2& lineDirA,
                const v2& linePointB, const v2& lineDirB,
                v2& outPointIntersection
        );

        inline int Intersect2dLines(
                const Line2& lineA,
                const Line2& lineB,
                v2& outPointIntersection)
        {
            return Intersect2dLines(
                    lineA.point, lineA.dir,
                    lineB.point, lineB.dir,
                    outPointIntersection);
        }
    }
}

