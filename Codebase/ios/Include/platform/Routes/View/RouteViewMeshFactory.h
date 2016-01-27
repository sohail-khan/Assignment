// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MeshFactory.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewMeshFactory : public Rendering::MeshFactories::MeshFactory
            {
            public:
                RouteViewMeshFactory(Rendering::GlBufferPool& glBufferPool, const Rendering::VertexLayouts::VertexLayout& vertexLayout, const size_t vertexSize);

                
                static Rendering::VertexLayouts::VertexLayout* CreateVertexLayout();

            };
        }
    }
}
