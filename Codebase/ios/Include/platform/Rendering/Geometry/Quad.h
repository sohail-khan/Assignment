// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Types.h"
#include "VectorMathDecl.h"
#include "Geometry.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Geometry
        {
            Eegeo::Rendering::Mesh* CreatePositionQuad(Rendering::GlBufferPool& glBufferPool, const Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool);
            
            Eegeo::Rendering::Mesh* CreatePositionQuad(float depthValue, Rendering::GlBufferPool& glBufferPool, const Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool);
            
            Eegeo::Rendering::Mesh* CreatePositionUVViewportQuad(Rendering::GlBufferPool& glBufferPool, const Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool);
            
            Eegeo::Rendering::Mesh* CreateTexturedViewportQuad(Rendering::GlBufferPool& glBufferPool, const Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool, const Eegeo::Geometry::Bounds2D& positionRectViewportNormalised, const Eegeo::Geometry::Bounds2D& uvRect);
            
            void BuildUnitQuad(std::vector<v3>& out_vertices, std::vector<u16>& out_indices);
        }
    }
}
