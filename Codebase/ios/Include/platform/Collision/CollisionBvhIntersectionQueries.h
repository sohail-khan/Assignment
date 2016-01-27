// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "CollisionBvh.h"
#include "RayNodeIntersectionResult.h"
#include "RayMeshIntersectionResult.h"
#include "RayNodeIntersectionResult.h"
#include "CollisionBvhNodeIntersectionTests.h"
#include "ArrayAllocator.h"
#include "SkewedRay.h"



#include <stack>
#include <vector>

namespace Eegeo
{
    namespace Collision
    {
        template <typename TOutputIter>
        inline TOutputIter GetLeafNodesIntersectingRay(
                                                const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                const Eegeo::v3& rayOrigin,
                                                const Eegeo::v3& rayDirection,
                                                TOutputIter rayNodeIntersectionResult);
        
        template <typename TOutputIter>
        inline TOutputIter GetLeafNodesIntersectingLineSegment(const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                        const Eegeo::v3& lineSegmentStart,
                                                        const Eegeo::v3& lineSegmentDirection,
                                                        float lineSegmentLength,
                                                        TOutputIter rayNodeIntersectionResult);

        template <typename TOutputIter>
        inline TOutputIter GetLeafNodesIntersectingSkewedRay(
                                                             const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                             const SkewedRay& skewedRay,
                                                             TOutputIter rayNodeIntersectionResult);
        
        template <typename TOutputIter>
        inline TOutputIter GetLeafNodesIntersectingSkewedRayBruteForce(const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                                const SkewedRay& skewedRay,
                                                                TOutputIter rayNodeIntersectionResult);
        
        
        RayMeshIntersectionResult RayMeshIntersection(const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                      const Eegeo::Collision::CollisionBvhNode& leafNode,
                                                      const Eegeo::v3& rayOrigin,
                                                      const Eegeo::v3& rayDirection,
                                                      const float skewedParamScale);
        
        
        SkewedRay CalcEnvironmentFlattenedSkewedRay(const v3& rayOrigin,
                                                    const v3& rayDirection,
                                                    const dv3& collisionBvhOriginEcef,
                                                    const float environmentFlatteningScale);
        
        m33 CalcEnvironmentFlatteningTransform(const dv3& meshOrigin, const float environmentFlatteningScale);
        
        
        namespace
        {
        	template <typename T, int MaxStackSize>
        	struct TStackAllocatedStack
        	{
        	private:
        		typedef Eegeo::Helpers::ArrayAllocator<T, MaxStackSize> IntArrayStackAllocator;
        		typedef std::vector<T, IntArrayStackAllocator> StackAllocatedVector;
        	public:
        		typedef std::stack<T, StackAllocatedVector> Type;
        	};

        	typedef TStackAllocatedStack<int, 1024>::Type WorkspaceStack;

            template <typename TIntegerStack, typename TIntersectionTest, typename TResultPredicate, typename TOutIter>
            inline TOutIter GetCollisionBvhLeafNodes(TIntegerStack& stack,
            										const Eegeo::Collision::CollisionBvh& collisionBvh,
            										TIntersectionTest intersectionTest,
            										TResultPredicate resultPredicate,
            										TOutIter outIterFirst)
            {
            	Eegeo_ASSERT(stack.empty());
                TOutIter outIter = outIterFirst;
                if (collisionBvh.Nodes().empty())
                    return outIter;
                
                const int RootNodeIndex = 0;
                stack.push(RootNodeIndex);
                
                const std::vector<Eegeo::Collision::CollisionBvhNode>& nodes = collisionBvh.Nodes();
                
                while (!stack.empty())
                {
                    int candidateNodeIndex = stack.top();
                    stack.pop();
                    
                    const Eegeo::Collision::CollisionBvhNode& candidate = nodes[candidateNodeIndex];
                    
                    const typename TIntersectionTest::result_type& result = intersectionTest(candidate);
                    if ( resultPredicate(result))
                    {
                        if (candidate.IsLeafNode())
                        {
                            *outIter++ = result;
                        }
                        else
                        {
                            const int indexOffset = candidate.FirstChildIndex();
                            const int end = indexOffset + candidate.ChildCount();
                            for (int i = indexOffset ; i < end; ++i)
                            {
                                stack.push(i);
                            }
                        }
                    }
                }
                
                return outIter;
            }
        }
        
        template <typename TOutputIter>
        inline TOutputIter GetLeafNodesIntersectingRay(
                                                const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                const Eegeo::v3& rayOrigin,
                                                const Eegeo::v3& rayDirection,
                                                TOutputIter rayNodeIntersectionResult)
        {
            const float skewedParamScale = 1.f;
            BvhNodeRayIntersectionTest intersectionTest(collisionBvh, rayOrigin, rayDirection, skewedParamScale);
            WorkspaceStack workspaceStack;
            
            return GetCollisionBvhLeafNodes(workspaceStack, collisionBvh, intersectionTest, BvhNodeIntersectionTestPredicate(), rayNodeIntersectionResult);
        }
        
        template <typename TOutputIter>
        inline TOutputIter GetLeafNodesIntersectingLineSegment(const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                        const Eegeo::v3& lineSegmentStart,
                                                        const Eegeo::v3& lineSegmentDirection,
                                                        float lineSegmentLength,
                                                        TOutputIter rayNodeIntersectionResult)
        {
            const float skewedParamScale = 1.f;
            BvhNodeLineSegmentIntersectionTest intersectionTest(collisionBvh, lineSegmentStart, lineSegmentDirection, lineSegmentLength, skewedParamScale);
            WorkspaceStack workspaceStack;
            
            return GetCollisionBvhLeafNodes(workspaceStack, collisionBvh, intersectionTest, BvhNodeIntersectionTestPredicate(), rayNodeIntersectionResult);
        }
        
        template <typename TOutputIter>
        inline TOutputIter GetLeafNodesIntersectingSkewedRay(
                                                             const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                             const SkewedRay& skewedRay,
                                                             TOutputIter rayNodeIntersectionResult)
        {
            BvhNodeRayIntersectionTest intersectionTest(collisionBvh, skewedRay.Origin, skewedRay.Direction, skewedRay.SkewedParamScale);
            WorkspaceStack workspaceStack;

            return GetCollisionBvhLeafNodes(workspaceStack, collisionBvh, intersectionTest, BvhNodeIntersectionTestPredicate(), rayNodeIntersectionResult);
        }
        
        template <typename TOutputIter>
        TOutputIter GetLeafNodesIntersectingSkewedRayBruteForce(const Eegeo::Collision::CollisionBvh& collisionBvh,
                                                                const SkewedRay& skewedRay,
                                                                TOutputIter rayNodeIntersectionResult)
        {
            TOutputIter outIter = rayNodeIntersectionResult;
            const std::vector<Eegeo::Collision::CollisionBvhNode>& nodes = collisionBvh.Nodes();
            for (int i = 0; i < nodes.size(); ++i)
            {
                const Eegeo::Collision::CollisionBvhNode& node = nodes[i];
                if (node.IsLeafNode())
                {
                    float t;
                    const Geometry::SingleSphere& sphere = collisionBvh.GetSphere(node);
                    if ( Geometry::IntersectionTests::SphereIntersectsWithRay(sphere, skewedRay.Origin, skewedRay.Direction, t))
                    {
                        t *= skewedRay.SkewedParamScale;
                        *outIter++ = Eegeo::Collision::RayNodeIntersectionResult(skewedRay.Origin, skewedRay.Direction, skewedRay.SkewedParamScale, collisionBvh, node, true, t);
                    }
                }
            }
            return outIter;
        }
        
    }
}
