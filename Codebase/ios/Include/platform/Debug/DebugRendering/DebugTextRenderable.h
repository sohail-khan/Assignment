// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "DebugRenderableBase.h"
#include "Rendering.h"
#include "Fonts.h"
#include "AllVertexTypes.h"

namespace Eegeo
{
    namespace DebugRendering
    {
        class DebugTextRenderable : public DebugRenderableBase
        {
        public:
            DebugTextRenderable(int vertexBufferSize,
                                int indexBufferSize,
                                Rendering::Materials::IMaterial* material,
                                const Rendering::VertexLayouts::VertexBinding& vertexBinding);
            
            ~DebugTextRenderable();
            
            void AddIndexElement(u16 indexToAdd);
            void AddTextVertexElement(const Rendering::VertexTypes::TextVertex& vertexToAdd);
            
            int GetCurrentVertexElementCount() const;
            
            bool ContainsMeshData() const;
            
            void Render(Rendering::GLState& glState) const;

        private:
            void BindBuffers(Rendering::GLState& glState) const;
            
            Rendering::DynamicBuffer<Rendering::VertexTypes::TextVertex>* m_pVertexBuffer;
            Rendering::DynamicBuffer<u16>* m_pIndexBuffer;
            
            const Rendering::VertexLayouts::VertexBinding& m_vertexBinding;
        };
    }
}