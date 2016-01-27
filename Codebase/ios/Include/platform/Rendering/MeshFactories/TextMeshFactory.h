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
             * \brief Factory for creating meshes with the TextVertex vertex format.
             */
            class TextMeshFactory : public MeshFactory
            {
            public:
                TextMeshFactory(Rendering::GlBufferPool& glBufferPool, const VertexLayouts::VertexLayoutPool& vertexLayoutPool)
                : MeshFactory(glBufferPool, vertexLayoutPool.GetForTextVertex(), sizeof(Rendering::VertexTypes::TextVertex))
                {
                }
            };
        }
    }
}
