// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "CollisionGroup.h"
#include "ICollisionBvhProvider.h"
#include "CollisionBvhRayCaster.h"
#include "ArrayAllocator.h"

#include <vector>

namespace Eegeo
{
    namespace Collision
    {
        template <size_t CollisionBvhBufferSize, size_t MaxRayNodeIntersectionResults>
        class StackAllocatedRayCaster : public Eegeo::NonCopyable
        {
        public:
#ifdef EEGEO_WIN
			typedef std::vector<const CollisionBvh*> CollisionBvhVector;
#else
			typedef std::vector<const CollisionBvh*, Eegeo::Helpers::ArrayAllocator<const CollisionBvh*, CollisionBvhBufferSize> > CollisionBvhVector;
#endif
            typedef std::vector<RayNodeIntersectionResult, Eegeo::Helpers::ArrayAllocator<RayNodeIntersectionResult, MaxRayNodeIntersectionResults> > RayNodeIntersectionResultVector;
            
            StackAllocatedRayCaster(const ICollisionBvhProvider& collisionBvhProvider)
            : m_collisionBvhProvider(collisionBvhProvider)
            {
                
            }

            RayCasterResult FindFirstRayIntersection(const u32 collidableGroupsMask, const float environmentFlatteningScale, const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection)
            {
                m_collisionBvhBuffer.resize(CollisionBvhBufferSize);
                
                const size_t totalCount = m_collisionBvhProvider.CopyCollisionBvhsForGroups(collidableGroupsMask, m_collisionBvhBuffer.data(), m_collisionBvhBuffer.size());
                Eegeo_ASSERT(totalCount <= m_collisionBvhBuffer.capacity(), "insufficient collisionBvhBuffer size, totalCount %ld", totalCount);
                m_collisionBvhBuffer.resize(totalCount);
                
                CollisionBvhRayCaster<CollisionBvhVector, RayNodeIntersectionResultVector> rayCaster(m_collisionBvhBuffer, m_rayNodeIntersectionResults);
                return rayCaster.FindFirstRayIntersection(environmentFlatteningScale, rayOrigin, rayDirection);
            }
        private:
            const ICollisionBvhProvider& m_collisionBvhProvider;
            CollisionBvhVector m_collisionBvhBuffer;
            RayNodeIntersectionResultVector m_rayNodeIntersectionResults;
            
            void * operator new [](size_t) throw() {return 0;}
            void operator delete [] (void*) {}
            void * operator new (size_t) throw() {return 0;}
            void operator delete (void*) {}
        };
    }
}