// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "Types.h"

#include <vector>
#include <limits>

namespace Eegeo
{
    namespace Collision
    {
        
        struct CollisionMaterialIndexLookupPair
        {
            CollisionMaterialIndexLookupPair()
            : FirstCollisionFaceIndex(0)
            , MaterialIndex(0)
            {}
            
            u32 FirstCollisionFaceIndex;
            u16 MaterialIndex;
        };
        
        
        struct ContiguousRangeBuilder
        {
            void Add(int collisionFaceIndex, u16 materialIndex)
            {
                if (m_pairs.empty() || m_pairs.back().MaterialIndex != materialIndex)
                {
                    CollisionMaterialIndexLookupPair pair;
                    Eegeo_ASSERT(collisionFaceIndex >= 0);
                    Eegeo_ASSERT(collisionFaceIndex <= std::numeric_limits<u32>::max());
                    pair.FirstCollisionFaceIndex = collisionFaceIndex;
                    pair.MaterialIndex = materialIndex;
                    m_pairs.push_back(pair);
                }
            }
            
            void Reserve(size_t capacity) { m_pairs.reserve(capacity); }
            void Clear() { m_pairs.clear(); }
            
            const std::vector<CollisionMaterialIndexLookupPair>& Pairs() const { return m_pairs; }
        private:
            std::vector<CollisionMaterialIndexLookupPair> m_pairs;
        };
    }
}