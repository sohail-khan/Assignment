// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "RayCasterResult.h"
#include "CollisionBvh.h"
#include "CollisionBvhIntersectionQueries.h"
#include "RayCasterFirstIntersectionBuilder.h"

#include <vector>
#include <algorithm>
#include <iterator>

namespace Eegeo
{
    namespace Collision
    {
        template <typename TCollisionBvhContainer, typename TRayNodeIntersectionResults >
        class CollisionBvhRayCaster : public Eegeo::NonCopyable
        {
        public:
            typedef typename TCollisionBvhContainer::const_iterator TCollisionBvhIter;
            
            CollisionBvhRayCaster(const TCollisionBvhContainer& collisionBvhs, TRayNodeIntersectionResults& rayNodeIntersectionsScratch)
            : m_collisionBvhs(collisionBvhs)
            , m_rayNodeIntersectionsScratch(rayNodeIntersectionsScratch)
            {}
            
            inline RayCasterResult FindFirstRayIntersection(const float environmentFlatteningScale, const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection) const;
            
        private:
            const TCollisionBvhContainer& m_collisionBvhs;
            TRayNodeIntersectionResults& m_rayNodeIntersectionsScratch;
        };
        
        namespace
        {
            inline bool RayNodeIntersectionResultSortByT(const Eegeo::Collision::RayNodeIntersectionResult& _a, const Eegeo::Collision::RayNodeIntersectionResult& _b)
            {
                return _a.IntersectionParam() < _b.IntersectionParam();
            }
            
            template <typename TCollisionBvhIter, typename TOutIter>
            TOutIter GatherLeafNodesIntersectingRay(const float environmentFlatteningScale, const Eegeo::dv3& rayOrigin, const Eegeo::v3& rayDirection, TCollisionBvhIter first, TCollisionBvhIter last, TOutIter outIter)
            {
                for (TCollisionBvhIter iter = first; iter != last; ++iter)
                {
                    const Eegeo::Collision::CollisionBvh& collisionBvh = **iter;
                    
                    v3 meshRelativeRayOrigin = (rayOrigin - collisionBvh.OriginEcef()).ToSingle();
                    
                    const SkewedRay& skewedRay = CalcEnvironmentFlattenedSkewedRay(meshRelativeRayOrigin, rayDirection, collisionBvh.OriginEcef(), environmentFlatteningScale);
                    
                    GetLeafNodesIntersectingSkewedRay(collisionBvh, skewedRay, outIter);
                }
                return outIter;
            }
        }

       
        template <typename TCollisionBvhContainer, typename TRayNodeIntersectionResults>
        inline RayCasterResult
        CollisionBvhRayCaster<TCollisionBvhContainer, TRayNodeIntersectionResults>::FindFirstRayIntersection(const float environmentFlatteningScale, const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection) const
        {
            typedef typename TRayNodeIntersectionResults::const_iterator TRayNodeIntersectionResultIter;
            
            m_rayNodeIntersectionsScratch.clear();
            GatherLeafNodesIntersectingRay(environmentFlatteningScale, rayOrigin, rayDirection.ToSingle(), m_collisionBvhs.begin(), m_collisionBvhs.end(), std::back_inserter(m_rayNodeIntersectionsScratch));
            
            
            std::sort(m_rayNodeIntersectionsScratch.begin(), m_rayNodeIntersectionsScratch.end(), RayNodeIntersectionResultSortByT);
            
            RayCasterFirstIntersectionBuilder firstIntersectionBuilder(rayOrigin, rayDirection, environmentFlatteningScale);
            
            for (TRayNodeIntersectionResultIter iter = m_rayNodeIntersectionsScratch.begin(); iter != m_rayNodeIntersectionsScratch.end(); ++iter)
            {
                bool shouldContinue = firstIntersectionBuilder(*iter);
                if (!shouldContinue)
                {
                    break;
                }
            }
            
            return firstIntersectionBuilder.BuildResult();
        }

    }
}