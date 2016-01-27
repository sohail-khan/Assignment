// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "Collision.h"
#include "Rendering.h"
#include "CollisionVisualization.h"
#include "VectorMath.h"


#include <vector>
#include <string>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class CollisionVisualizationRenderableFactory : public Eegeo::NonCopyable
        {
        public:
            CollisionVisualizationRenderableFactory(
                                                    CollisionVisualizationMaterial& material,
                                                    Rendering::MeshFactories::PositionMeshFactory& positionMeshFactory,
                                                    Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool
                                                    );
            
            virtual ~CollisionVisualizationRenderableFactory();
            
            virtual CollisionVisualizationRenderable* CreateFromSubMesh(const Collision::CollisionSubMesh& collisionSubMesh, const v4& color);
        private:
            CollisionVisualizationMaterial& m_material;
            Rendering::MeshFactories::PositionMeshFactory& m_positionMeshFactory;
            Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
        };
    }
}