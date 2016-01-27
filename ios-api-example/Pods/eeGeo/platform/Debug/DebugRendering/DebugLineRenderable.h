// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "DebugRenderableBase.h"
#include "Rendering.h"
#include "AllVertexTypes.h"

namespace Eegeo
{
    namespace DebugRendering
    {
        class DebugLineRenderable : public DebugRenderableBase
        {
        public:
            DebugLineRenderable(int vertexBufferSize,
                                Rendering::Materials::IMaterial* material,
                                float lineWidth,
                                const Rendering::VertexLayouts::VertexBinding& vertexBinding);
            
            ~DebugLineRenderable();
            
            void Render(Rendering::GLState& glState) const;
            
            void AddVertexElement(const Rendering::VertexTypes::ColoredVertex& vertexToAdd);
            bool ContainsMeshData() const;
            
            void SetLineWidth(float lineWidth);
            
        private:
            void BindBuffers(Rendering::GLState& glState) const;
            
            Rendering::DynamicBuffer<Rendering::VertexTypes::ColoredVertex>* m_pVertexBuffer;
            
            const Rendering::VertexLayouts::VertexBinding& m_vertexBinding;
            float m_lineWidth;
        };
    }
}