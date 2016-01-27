// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MeshFactory.h"
#include "VertexLayoutPool.h"
#include "AllVertexTypes.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace MeshFactories
        {
            /*!
             * \brief Factory for creating meshes with the PackTowTextureVertex vertex format.
             */
            class PackedTwoTextureDiffuseMeshFactory : public MeshFactory
            {
            public:
                PackedTwoTextureDiffuseMeshFactory(Rendering::GlBufferPool& glBufferPool, const VertexLayouts::VertexLayoutPool& vertexLayoutPool)
                : MeshFactory(glBufferPool, vertexLayoutPool.GetForPackedTwoTextureVertex(), sizeof(Rendering::VertexTypes::PackedTwoTextureVertex))
                {
                }
            };
        }
    }
}
