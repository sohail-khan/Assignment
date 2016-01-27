// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Collision
    {
        struct RayNodeIntersectionResult
        {
            RayNodeIntersectionResult()
            : m_rayOrigin(v3::Zero())
            , m_rayDirection(v3::Zero())
            , m_skewedRayParamScale(0.f)
            , m_pCollisionBvh(NULL)
            , m_pNode(NULL)
            , m_bIntersects(false)
            , m_intersectionParam(0.f)
            {}
            
            RayNodeIntersectionResult(const v3& rayOrigin, const v3& rayDirection, float skewedRayParamScale, const CollisionBvh& collisionBvh, const CollisionBvhNode& node, bool intersects, float intersectionParam)
            : m_rayOrigin(rayOrigin)
            , m_rayDirection(rayDirection)
            , m_skewedRayParamScale(skewedRayParamScale)
            , m_pCollisionBvh(&collisionBvh)
            , m_pNode(&node)
            , m_bIntersects(intersects)
            , m_intersectionParam(intersectionParam)
            {
            }
            
            const v3& RayOrigin() const { return m_rayOrigin; }
            const v3& RayDirection() const { return m_rayDirection; }
            float SkewedRayParamScale() const { return m_skewedRayParamScale; }
            const CollisionBvh& Bvh() const { return *m_pCollisionBvh; }
            const CollisionBvhNode& Node() const { return *m_pNode; }
            bool Intersects() const { return m_bIntersects; }
            float IntersectionParam() const { return m_intersectionParam; }
        private:
            v3 m_rayOrigin;
            v3 m_rayDirection;
            float m_skewedRayParamScale;
            const CollisionBvh* m_pCollisionBvh;
            const CollisionBvhNode* m_pNode;
            bool m_bIntersects;
            float m_intersectionParam;
        };
    }
}