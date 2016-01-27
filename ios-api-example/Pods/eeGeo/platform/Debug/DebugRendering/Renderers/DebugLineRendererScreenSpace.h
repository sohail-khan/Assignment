// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "VectorMath.h"
#include "DynamicBuffer.h"
#include "Rendering.h"
#include "AllVertexTypes.h"
#include "Streaming.h"
#include "CameraFrustumStreamingVolume.h"
#include "DebugLineRenderable.h"
#include "IRenderableFilter.h"

namespace Eegeo
{
    namespace DebugRendering
    {
        namespace Renderers
        {
            class DebugLineRendererScreenSpace : public Rendering::IRenderableFilter
            {

            struct DebugLineScreenSpace
            {
                v4 Color;
                v2 P0;
                v2 P1;
                float Lifetime;
            };

            public:
                DebugLineRendererScreenSpace(Rendering::Materials::IMaterial* material,
                                             const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                             int vertexBufferSize,
                                             float lineWidth);

                ~DebugLineRendererScreenSpace();

                void SetLineWidth(float lineWidth);

                void DrawLine(
                        const v2& screenPointA,
                        const v2& screenPointB,
                        const v4& color,
                        const float lifetime = 0.0f
                );

                void Update(float dt);
                void GenerateGeometry();
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
                
                void SetDepthEnabled(const bool depthEnabled);

            private:
               
                std::vector<DebugLineScreenSpace> m_drawData;
                
                DebugLineRenderable* m_pDebugLineRenderable;
            };
        }
    }
}


