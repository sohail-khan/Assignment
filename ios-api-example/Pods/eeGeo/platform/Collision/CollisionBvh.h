// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Collision.h"
#include "VectorMath.h"
#include "CollisionBvhNode.h"
#include "CollisionMaterialIndexLookupPair.h"
#include "CollisionGroup.h"
#include "CollisionMaterialTable.h"
#include "AllVertexTypes.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Collision
    {
        class CollisionBvh
        {
        public:
            CollisionBvh();
            
            CollisionBvh(const Eegeo::dv3& originEcef,
                         const v3& quantizationRelativeOrigin,
                         float quantizationScale,
                         float minAltitude,
                         float maxAltitude,
                         CollisionGroup::Type collisionGroup,
                         std::vector<Rendering::VertexTypes::ShortPositionVertex>* pPoints,
                         std::vector<u16>* pTriListIndices,
                         std::vector<CollisionBvhNode>* pNodes,
                         const std::vector<CollisionMaterialIndexLookupPair>* pMaterialIndexLookupPairs,
                         const CollisionMaterialTable* pCollisionMaterialTable);
            
            ~CollisionBvh();
            
            const dv3& OriginEcef() const { return m_originEcef; }
            const v3& QuantizationRelativeOrigin() const { return m_quantizationRelativeOrigin; }
            float QuantizationScale() const { return m_quantizationScale; }
            CollisionGroup::Type CollisionGroup() const { return m_collisionGroup; }
            const std::vector<Rendering::VertexTypes::ShortPositionVertex>& QuantizedPoints() const { return *m_pPoints; }
            const std::vector<u16>& TriListIndices() const { return *m_pTriListIndices; }
            const std::vector<CollisionBvhNode>& Nodes() const { return *m_pNodes; }
            int FindMeshIndexForTriangle(int triangleIndex) const;
            const float MinAltitude() const { return m_minAltitude; }
            const float MaxAltitude() const { return m_maxAltitude; }
            
            inline v3 GetInflatedPoint(int vertexIndex) const;
            
            inline Eegeo::Geometry::SingleSphere GetSphere(const CollisionBvhNode& node) const;
            
            std::string CollisionMaterialIdForIndex(int materialIndex) const { return (materialIndex < 0) ? std::string() : m_pCollisionMaterialTable->IdAtIndex(materialIndex); }
            
            std::vector<u16> GatherTriListIndicesForMaterialIndex(const int materialIndex) const;
            
            const CollisionMaterialTable& GetCollisionMaterialTable() const { return *m_pCollisionMaterialTable; }
        private:
            const dv3 m_originEcef;
            const v3 m_quantizationRelativeOrigin;
            const float m_quantizationScale;
            const float m_minAltitude;
            const float m_maxAltitude;
            const CollisionGroup::Type m_collisionGroup;
            const std::vector<Rendering::VertexTypes::ShortPositionVertex>* m_pPoints;
            const std::vector<u16>* m_pTriListIndices;
            const std::vector<CollisionBvhNode>* m_pNodes;
            const std::vector<CollisionMaterialIndexLookupPair>* m_pMaterialIndexLookupPairs;
            const CollisionMaterialTable* m_pCollisionMaterialTable;
        };
        
        inline v3 CollisionBvh::GetInflatedPoint(int vertexIndex) const
        {
            Eegeo_ASSERT_SLOW(vertexIndex >= 0 && vertexIndex < m_pPoints->size(), "vertex index out of range");
            
            const Rendering::VertexTypes::ShortPositionVertex& q = (*m_pPoints)[vertexIndex];
            v3 p(q.x, q.y, q.z);
            p *= m_quantizationScale;
            p += m_quantizationRelativeOrigin;
            return p;
        }

        inline Eegeo::Geometry::SingleSphere CollisionBvh::GetSphere(const CollisionBvhNode& node) const
        {
            Eegeo::Geometry::SingleSphere sphere;
            const Eegeo::Rendering::VertexTypes::ShortPositionVertex& qc = node.QuantizedSphereCentre();
            sphere.centre.x = qc.x;
            sphere.centre.y = qc.y;
            sphere.centre.z = qc.z;
            sphere.centre *= m_quantizationScale;
            sphere.centre += m_quantizationRelativeOrigin;
            sphere.radius = node.QuantizedSphereRadius()*m_quantizationScale;
            return sphere;
        }

    }
}