// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "CollisionVisualization.h"
#include "Rendering.h"
#include "Collision.h"
#include "Types.h"

#include <vector>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintSelectionRenderableFactory : private Eegeo::NonCopyable
        {
        public:
            typedef std::vector<BuildingFootprint> FootprintVector;
            BuildingFootprintSelectionRenderableFactory(CollisionVisualization::CollisionVisualizationMaterial& material,
                                                        Rendering::MeshFactories::PositionMeshFactory& positionMeshFactory,
                                                        Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
            
            CollisionVisualization::CollisionVisualizationRenderable* Create(const FootprintVector& footprints);
        private:
            struct BufferSizes
            {
                BufferSizes(): VertexCount(0), IndexCount(0) {}
                
                size_t VertexCount;
                size_t IndexCount;
            };
            
            BufferSizes CalcBufferSizes(const FootprintVector& footprints);
            
            CollisionVisualization::CollisionVisualizationMaterial& m_material;
            Rendering::MeshFactories::PositionMeshFactory& m_positionMeshFactory;
            Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
        };
    }
}