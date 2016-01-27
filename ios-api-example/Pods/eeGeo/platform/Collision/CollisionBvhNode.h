// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "SingleSphere.h"
#include "Types.h"
#include "AllVertexTypes.h"

#include "VectorMath.h"

namespace Eegeo
{
    namespace Collision
    {
        struct CollisionBvhNode
        {
        public:

            CollisionBvhNode()
            {}
            
            CollisionBvhNode(const Eegeo::Rendering::VertexTypes::ShortPositionVertex& quantizedSphereCentre, u16 quantizedSphereRadius, u32 packedRanges);
            
            static CollisionBvhNode Make(const Eegeo::Rendering::VertexTypes::ShortPositionVertex& quantizedSphereCentre, u16 quantizedSphereRadius, int firstChildIndex, int childCount, bool isLeaf);
            
            const Eegeo::Rendering::VertexTypes::ShortPositionVertex& QuantizedSphereCentre() const { return m_quantizedSphereCentre; }
            u16 QuantizedSphereRadius() const { return m_quantizedSphereRadius; }
            
            inline int FirstChildIndex() const;
            inline int ChildCount() const;
            inline bool IsLeafNode() const;
            
        private:
            Eegeo::Rendering::VertexTypes::ShortPositionVertex m_quantizedSphereCentre;
            u16 m_quantizedSphereRadius;
            u32 m_packedRanges;
            
            enum
            {
                ChildCountBits = 12,
                ChildCountMask = (1 << ChildCountBits) - 1,
                
                FirstChildIndexBits = 19,
                FirstChildIndexShift = ChildCountBits,
                MaxFirstChildIndex = (1 << FirstChildIndexBits) - 1,
                FirstChildIndexMask = MaxFirstChildIndex << FirstChildIndexShift,
                
                IsLeafShift = FirstChildIndexShift + FirstChildIndexBits,
                IsLeafMask = (1 << IsLeafShift)
            };
        };
        
        inline int CollisionBvhNode::FirstChildIndex() const
        {
            return (m_packedRanges & FirstChildIndexMask) >> FirstChildIndexShift;
        }
        
        inline int CollisionBvhNode::ChildCount() const
        {
            return m_packedRanges & ChildCountMask;
        }
        
        inline bool CollisionBvhNode::IsLeafNode() const
        {
            return ((m_packedRanges & IsLeafMask) != 0) ? true : false;
        }
    }
}