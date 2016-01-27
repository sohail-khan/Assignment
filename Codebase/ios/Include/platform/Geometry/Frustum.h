// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Plane.h"
#include "Geometry.h"
#include <vector>

namespace Eegeo
{
    namespace Geometry
    {
        void BuildFrustumPlanesFromViewProjection(std::vector<Geometry::Plane> &frustumPlanes, const Eegeo::m44& viewProjection);
        
        class Frustum
        {
        public:

            static const int PLANE_LEFT = 0;
            static const int PLANE_RIGHT = 1;
            static const int PLANE_BOTTOM = 2;
            static const int PLANE_TOP = 3;
            static const int PLANE_NEAR = 4;
            static const int PLANE_FAR = 5;
            static const int PLANES_COUNT = 6;
            Geometry::Plane planes[PLANES_COUNT];
            
            
            void Update(const std::vector<Geometry::Plane>& frustumPlanes)
            {
                for (int i = 0; i < 6; ++ i)
                {
                    planes[i] = frustumPlanes[i].Norm();
                }
            }
            
            const Geometry::Plane& operator[]  (const int index) const
            {
                return planes[index];
            }
            
            void CalculateVertexPositions(std::vector<Eegeo::v3>& verts) const;
            
            bool Intersects(const SingleSphere& sphere) const;
            
            static Frustum Transform(const Frustum& frustum, const m44& nonScalingTransform);
            
        private:
            void IntersectPlanes(const Plane& p1, const Plane& p2, const Plane& p3, Eegeo::v3& intersectionPoint)const;
        };
    }    
}
