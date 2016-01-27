// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "IdTypes.h"
#include "VAOCache.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief A renderable mesh.
         *
         * This class holds the geometry for a renderable mesh along with the additional information required to render that mesh.
         */
        class Mesh : protected Eegeo::NonCopyable
        {            
        public:
            Mesh(
                 const VertexLayouts::VertexLayout& vertexLayout,
                 Rendering::GlBufferPool& glBufferPool,
                 const void* pVertexData,
                 size_t vertexDataSize,
                 const void* pIndexData,
                 size_t indexDataSize,
                 u32 numOfIndices,
                 const std::string& debugName
                  );
            
            ~Mesh();
            
            const VertexLayouts::VertexLayout& GetVertexLayout() const { return m_vertexLayout; }
            
            u32 GetNumOfIndices() const { return m_numOfIndices; }
            TVertexBufferId GetVertexBuffer() const { return m_glVertexBuffer; }
            TIndexBufferId GetIndexBuffer() const { return m_glIndexBuffer; }
            
            void BindVertexBuffers(const VertexLayouts::VertexBinding* pVertexBinding, Rendering::GLState& glState);
            
            void UnbindVertexBuffers(Rendering::GLState& glState);
                        
        protected:
            const VertexLayouts::VertexLayout& m_vertexLayout;
            Rendering::GlBufferPool& m_glBufferPool;
            TVertexBufferId m_glVertexBuffer;
            TIndexBufferId m_glIndexBuffer;
            u32 m_numOfIndices;
            const std::string m_debugName;
#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
            VAOCache m_vaoCache;
#endif
        };
    }
}
