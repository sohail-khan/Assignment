// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRayPicker.h"
#include "VectorMath.h"
#include "RayNodeIntersectionResult.h"

#include <vector>
#include <deque>

namespace Eegeo
{
    namespace Collision
    {
        /*!
         *  Implements IRayPicker to provide ray intersection query against all collision mesh resources provided
         *  by the construction-injected ICollisionBvhProvider instance
         */
        class CollisionMeshRayPicker : public IRayPicker, protected Eegeo::NonCopyable
        {
        public:
            CollisionMeshRayPicker(const ICollisionBvhProvider& provider);
            
            virtual ~CollisionMeshRayPicker();
            
            /*!
             *  Performs a ray intersection query against the triangles of all collision mesh resources obtained from a
             *  query to the constructor-provided ICollisionBvhProvider instance.
             *  If the ray intersects the mesh at multiple points, finds the first intersection (closest to rayOrigin).
             *  If an intersection is found, returns true, with intersection information passed in out parameters.
             *  \param rayOrigin start point of ray, in Ecef coordinates
             *  \param rayDirection normalised direction of ray, in Ecef coordinates
             *  \param out_ecefIntersectionPoint [out] closest point of intersection in Ecef coordinates if successful, else zero vector
             *  \param out_param [out] distance in metres from rayOrigin to out_ecefIntersectionPoint if successful, else zero
             *  \return true if intersection found, else false
             */
            virtual bool TryGetRayIntersection(const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection, Eegeo::dv3& out_ecefIntersectionPoint, double& out_param);
            
        private:
            const ICollisionBvhProvider& m_collisionBvhProvider;
            
            typedef std::vector<const CollisionBvh*> CollisionBvhBuffer;
            CollisionBvhBuffer m_collisionBvhBuffer;
            
            typedef std::deque<RayNodeIntersectionResult> RayNodeIntersectionsBuffer;
            RayNodeIntersectionsBuffer m_rayNodeIntersectionsBuffer;
        };
    }
}
