// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "RenderableBase.h"
#include "Rendering.h"
#include "Camera.h"
#include "DynamicBuffer.h"
#include "AllVertexTypes.h"
#include "IdTypes.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            namespace BatchedSpriteAnchor
            {
                enum Values
                {
                    Centre,
                    Bottom
                };
            }

            class BatchedSpriteRenderable : public RenderableBase
            {
            public:
                BatchedSpriteRenderable(
                        LayerIds::Values layerId,
                        Materials::IMaterial* pMaterial,
                        const VertexLayouts::VertexBinding& vertexBinding,
                        Rendering::GlBufferPool& glBufferPool,
                        BatchedSpriteAnchor::Values anchor);

                ~BatchedSpriteRenderable();

                void AddSprite(const Camera::RenderCamera& camera, const dv3& ecefPosition, const Eegeo::v2& uvsMin, const Eegeo::v2& uvsMax, const v4& color, const Eegeo::v2& dimensionsInMeters);

                void SetMaterial(const Materials::IMaterial* pMaterial, VertexLayouts::VertexBindingPool& vertexBindingPool);

                void Render(GLState& glState) const;
                
                void Reset();

            private:
                DynamicBuffer<Rendering::VertexTypes::TexturedColoredVertex>* m_pVertexBuffer;
                TIndexBufferId m_glIndexBuffer;
                BatchedSpriteAnchor::Values m_anchor;
                u32 m_spriteCount;
                GlBufferPool& m_glBufferPool;
            };
        }
    }
}