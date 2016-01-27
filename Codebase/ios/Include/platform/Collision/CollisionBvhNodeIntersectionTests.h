// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "CollisionBvhNode.h"
#include "RayNodeIntersectionResult.h"
#include "IntersectionTests.h"
#include "CollisionBvh.h"

#include <functional>

namespace Eegeo
{
    namespace Collision
    {
        struct BvhNodeRayIntersectionTest : public std::unary_function<CollisionBvhNode, RayNodeIntersectionResult>
        {
            BvhNodeRayIntersectionTest(const CollisionBvh& collisionBvh, Eegeo::v3 rayOrigin, Eegeo::v3 rayDirection, float skewedParamScale)
            : m_collisionBvh(collisionBvh)
            , m_rayOrigin(rayOrigin)
            , m_rayDirection(rayDirection)
            , m_skewedParamScale(skewedParamScale)
            {

            }
            
            RayNodeIntersectionResult operator() (const CollisionBvhNode& candidate) const
            {
                float t;
                const Geometry::SingleSphere& sphere = m_collisionBvh.GetSphere(candidate);
                bool intersects = Geometry::IntersectionTests::SphereIntersectsWithRay(sphere, m_rayOrigin, m_rayDirection, t);
                t *= m_skewedParamScale;
                RayNodeIntersectionResult result(m_rayOrigin, m_rayDirection, m_skewedParamScale, m_collisionBvh, candidate, intersects, t);
                return result;
            }
            
        private:
            const CollisionBvh& m_collisionBvh;
            const Eegeo::v3 m_rayOrigin;
            const Eegeo::v3 m_rayDirection;
            const float m_skewedParamScale;
        };
        
        struct BvhNodeLineSegmentIntersectionTest : public std::unary_function<CollisionBvhNode, RayNodeIntersectionResult>
        {
            BvhNodeLineSegmentIntersectionTest(const CollisionBvh& collisionBvh, Eegeo::v3 rayOrigin, Eegeo::v3 rayDirection, float lineSegmentLength, float skewedParamScale)
            : m_collisionBvh(collisionBvh)
            , m_rayOrigin(rayOrigin)
            , m_rayDirection(rayDirection)
            , m_lineSegmentLength(lineSegmentLength)
            , m_skewedParamScale(skewedParamScale)
            {
                
            }
            
            RayNodeIntersectionResult operator() (const CollisionBvhNode& candidate) const
            {
                float t;
                const Geometry::SingleSphere& sphere = m_collisionBvh.GetSphere(candidate);
                
                bool intersectsRay = Geometry::IntersectionTests::SphereIntersectsWithRay(sphere, m_rayOrigin, m_rayDirection, t);
                t *= m_skewedParamScale;
                bool intersectsLineSegment = intersectsRay && (t <= m_lineSegmentLength);
                RayNodeIntersectionResult result(m_rayOrigin, m_rayDirection, m_skewedParamScale, m_collisionBvh, candidate, intersectsLineSegment, t);
                return result;
            }
            
        private:
            const CollisionBvh& m_collisionBvh;
            const Eegeo::v3 m_rayOrigin;
            const Eegeo::v3 m_rayDirection;
            const float m_lineSegmentLength;
            const float m_skewedParamScale;
        };
        
        struct BvhNodeIntersectionTestPredicate : public std::unary_function<RayNodeIntersectionResult, bool>
        {
            bool operator() (const RayNodeIntersectionResult& testResult) const
            {
                return testResult.Intersects();
            }
        };
    }
}