// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Geometry.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Geometry
    {
        namespace LineSegments
        {
            double DistanceLineSegmentToPoint(const dv3& lineSegmentStart, const dv3& lineSegmentEnd, const dv3& point, double& out_param);
            double DistanceSqrLineSegmentToPoint(const dv3& lineSegmentStart, const dv3& lineSegmentEnd, const dv3& point, double& out_param);
            
            
            float DistanceLineSegmentToPoint(const v3& lineSegmentStart, const v3& lineSegmentEnd, const v3& point, float& out_param);
            float DistanceSqrLineSegmentToPoint(const v3& lineSegmentStart, const v3& lineSegmentEnd, const v3& point, float& out_param);
            float DistanceSqrLineSegmentToPoint(const v3& lineSegmentStart, const v3& lineSegmentEnd, const v3& point);
            float DistanceBetweenLineSegments(const v3& startA, const v3& endA, const v3& startB, const v3& endB, float& out_paramA, float& paramB);
            float DistanceSqrBetweenLineSegments(const v3& startA, const v3& endA, const v3& startB, const v3& endB, float& out_paramA, float& paramB);
            float ProjectPointOntoLineSegment(const v3& lineSegmentStart, const v3& lineSegmentEnd, const v3& point);

            bool IntersectsSphere(const v3& lineSegmentStart, const v3& lineSegmentEnd, const v3& sphereCentre, float sphereRadiusSq);
        }
    }
}
