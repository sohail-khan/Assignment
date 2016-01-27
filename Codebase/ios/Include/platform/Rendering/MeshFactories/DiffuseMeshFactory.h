// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MeshFactory.h"
#include "Rendering.h"
#include "VertexLayoutPool.h"
#include "AllVertexTypes.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace MeshFactories
        {
            class DiffuseMeshFactory : public MeshFactory
            {
            public:
                DiffuseMeshFactory(Rendering::GlBufferPool& glBufferPool, const VertexLayouts::VertexLayoutPool& vertexLayoutPool)
                : MeshFactory(glBufferPool, vertexLayoutPool.GetForDiffuseVertex(), sizeof(VertexTypes::DiffuseVertex))
                {
                }
            };
        }
    }
}