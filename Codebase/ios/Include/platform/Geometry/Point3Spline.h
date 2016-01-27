// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Geometry.h"
#include "VectorMath.h"
#include "Bounds.h"
#include <vector>

namespace Eegeo
{
    namespace Geometry
    {
        class Point3Spline
        {
        public:
            Point3Spline(const std::vector<v3>& points, const std::vector<float>& splineParams, float splineLength, const Bounds3D& bounds);
            const std::vector<v3>& Points() const { return m_points; }
            const std::vector<float>& SplineParams() const { return m_splineParams; }
            float SplineLength() const { return m_splineLength; }
            int Count() const { return static_cast<int>(m_points.size()); }
            const Bounds3D& Bounds() const { return m_bounds; }
            
            v3 GetInterpolatedPoint(float t) const;
            
            float DistanceToPoint(const v3& point, float& out_paramAtClosestApproach) const;
            
            float DistanceToLineSegment(const v3& pointA, const v3& pointB, float& out_paramOnSpline, float& paramOnLineSegment) const;
            
            float DistanceNearestPointToLineSegment(const v3& pointA, const v3& pointB, float& out_paramOnSpline, float& paramOnLineSegment) const;
            
            int IndexImmediatelyBefore(float param) const;
            
            bool IntersectsSphere(const Geometry::SingleSphere& sphere) const;
            
            bool IntersectsCapsule(const v3& capsulePointA, const v3& capsulePointB, const float capsuleRadius) const;
            
            static Point3Spline* CreateFromPoints(const std::vector<v3>& points);
            

            
        private:
            std::vector<v3> m_points;
            std::vector<float> m_splineParams;
            float m_splineLength;
            Bounds3D m_bounds;
            
        };
    }
}
