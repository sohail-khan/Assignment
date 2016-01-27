// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace MeshFactories
        {
            /*!
             * \brief Base class for mesh factories.
             */
            class MeshFactory : protected Eegeo::NonCopyable
            {
            public:
                Mesh* CreateMesh(
                                  const void* pVertexData,
                                  int numOfVertices,
                                  const void* pIndexData,
                                  size_t indexDataSize,
                                  u32 numOfIndices,
                                  const std::string& debugName
                                  ) const;
                
            protected:
                MeshFactory(Rendering::GlBufferPool& glBufferPool, const VertexLayouts::VertexLayout& vertexLayout, const size_t vertexSize)
                : m_glBufferPool(glBufferPool)
                , m_vertexLayout(vertexLayout)
                , m_vertexSize(vertexSize)
                {
                }

                Rendering::GlBufferPool& m_glBufferPool;
                const VertexLayouts::VertexLayout& m_vertexLayout;
                size_t m_vertexSize;
            };
        }
    }
}
