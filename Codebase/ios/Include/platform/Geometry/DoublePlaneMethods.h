// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#ifndef __apps_on_maps__DoublePlaneMethods__
#define __apps_on_maps__DoublePlaneMethods__


#include "Geometry.h"
#include "VectorMath.h"

#include <vector>

namespace Eegeo
{
    namespace Geometry
    {
        namespace DoublePlanes
        {
            bool IntersectsLineSegment(const DoublePlane& plane, const dv3& lineSegmentStart, const dv3& lineSegmentEnd, dv3& out_intersectionPoint, double& out_param);
            
            
            enum LineSegmentClassification
            {
                LineSegmentClassification_PositiveSide,
                LineSegmentClassification_NegativeSide,
                LineSegmentClassification_Intersects_StartOnPositiveSide,
                LineSegmentClassification_Intersects_StartOnNegativeSide
            };
            
            LineSegmentClassification ClassifyLineSegment(const DoublePlane& plane, const dv3& lineSegmentStart, const dv3& lineSegmentEnd, double& out_param);
        }
    }
}

#endif /* defined(__apps_on_maps__DoublePlaneMethods__) */
