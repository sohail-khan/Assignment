// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Geometry.h"

namespace Eegeo
{
    namespace Geometry
    {
        // TODO: split this into methods in an Intersection3d.h file & multiple impl files
        class IntersectionTests
        {
        public:
            static bool TestSphereSphere(Eegeo::dv3 ca, double ra, Eegeo::dv3 cb, double rb);
            static bool IntersectSegmentTriangle(Eegeo::dv3 p,
                                                 Eegeo::dv3 q,
                                                 Eegeo::dv3 a,
                                                 Eegeo::dv3 b,
                                                 Eegeo::dv3 c,
                                                 double &u,
                                                 double &v,
                                                 double &w,
                                                 double &t);
            static bool TestRaySphere(Eegeo::dv3 p,Eegeo::dv3 d,Eegeo::dv3 sc,double sr);
            static bool GetRayEarthSphereIntersection(const Eegeo::dv3& rayStart,
                                                      const Eegeo::dv3& rayDir,
                                                      Eegeo::dv3& out_closestIntersectionPoint);
            static bool GetRayEarthSphereIntersection(const Eegeo::dv3& rayStart,
                                                      const Eegeo::dv3& rayDir,
                                                      Eegeo::dv3& out_closestIntersectionPoint,
                                                      double squaredRadious);
            
            static bool SphereIntersectsWithRay(const SingleSphere& sphere, const Eegeo::v3& rayStartPoint, const Eegeo::v3& rayDirection);
            
            static bool SphereIntersectsWithRay(const SingleSphere& sphere, const Eegeo::v3& rayStartPoint, const Eegeo::v3& rayDirection, float &t);
            
            static bool SphereIntersectsWithSphere(const SingleSphere& a, const SingleSphere& b);
            
            static bool TriangleIntersectsWithRay(const Eegeo::v3& rayOrigin,
                                                 const Eegeo::v3& rayDirection,
                                                 const Eegeo::v3& a,
                                                 const Eegeo::v3& b,
                                                 const Eegeo::v3& c,
                                                 double& t);
            
            static bool IntersectFrustumSphere(const Geometry::Frustum& frustum,
                                               const v3& frustumRelativeSphereCenter,
                                               const float sphereRadius,
                                               uint& inactivePlaneFlags);
            
            static bool RayIntersectsWithPlane(const Eegeo::dv3 & rayOrigin,
                                               const Eegeo::dv3 & rayDir,
                                               const Eegeo::dv3 & planeNormal,
                                               const Eegeo::dv3 & planePoint,
                                               double & out_t,
                                               Eegeo::dv3& out_intersectPoint);
        };
    }
}
