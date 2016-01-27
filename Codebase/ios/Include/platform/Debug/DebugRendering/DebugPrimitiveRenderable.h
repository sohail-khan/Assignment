// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "DebugRenderableBase.h"
#include "Rendering.h"
#include "DynamicBuffer.h"
#include "AllVertexTypes.h"
#include "Types.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace DebugRendering
    {
        class DebugPrimitiveRenderable : public DebugRenderableBase
        {
        public:
            DebugPrimitiveRenderable(int vertexBufferSize,
                                     int indexBufferSize,
                                     Rendering::Materials::IMaterial* material,
                                     const Rendering::VertexLayouts::VertexBinding& vertexBinding);
            
            ~DebugPrimitiveRenderable();
            
            void AddVertexElement(const Rendering::VertexTypes::ColoredVertex& vertexToAdd);
            void AddIndexElement(const u16& indexToAdd);
            
            int GetCurrentVertexElementCount() const;
            
            bool ContainsMeshData() const;

            void Render(Rendering::GLState& glState) const;
            
        private:
            void BindBuffers(Rendering::GLState& glState) const;
            
            Rendering::DynamicBuffer<Rendering::VertexTypes::ColoredVertex>* m_pVertexBuffer;
            Rendering::DynamicBuffer<u16>* m_pIndexBuffer;
            const Rendering::VertexLayouts::VertexBinding& m_vertexBinding;
        };
    }
}