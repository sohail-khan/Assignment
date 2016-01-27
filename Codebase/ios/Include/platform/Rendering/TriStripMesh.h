// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Mesh.h"
#include "Rendering.h"
#include "IdTypes.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        /*!
        * \brief A renderable triangle strip mesh.
        *
        * This class holds the geometry for a renderable mesh along with the information on the triangle strip lengths used to render it.
        */
        class TriStripMesh : public Mesh
        {
        public:
            TriStripMesh(const VertexLayouts::VertexLayout& vertexLayout,
                         Rendering::GlBufferPool& glBufferPool,
                         const void* pVertexData,
                         size_t vertexDataSize,
                         const void* pIndexData,
                         size_t indexDataSize,
                         u32 numOfIndices,
                         std::vector<u32> triStripLengths,
                         const std::string& debugName);
            
            const bool UsesIndices() const { return m_usesIndices; }
            
            const u32 GetStripLength(u32 stripIndex) const;
            const size_t GetStripCount() const { return m_triStripLengths.size(); }

        private:
            
            std::vector<u32> m_triStripLengths;
            const bool m_usesIndices;
        };
    }
}