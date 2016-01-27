// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "VectorMathDecl.h"
#include "Geometry.h"


namespace Eegeo
{
    namespace Rendering
    {
        namespace Geometry
        {
            Eegeo::Rendering::Mesh* CreateUntexturedViewportNineSliceBorder(
                Rendering::GlBufferPool& glBufferPool,
                const Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                const Eegeo::Geometry::Bounds2D& innerRectangleOriginBottomLeft);
        }
    }
}
