// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "VectorMath.h"
#include "DynamicBuffer.h"
#include "Rendering.h"
#include "AllVertexTypes.h"
#include "Streaming.h"
#include "DebugLineRenderable.h"
#include "Camera.h"
#include "IRenderableFilter.h"

namespace Eegeo
{
    namespace DebugRendering
    {
        namespace Renderers
        {
            class DebugLineRendererEcef : public Rendering::IRenderableFilter
            {
                struct DebugLineEcef
                {
                    dv3 P0;
                    dv3 P1;
                    v4 Color;
                    float Lifetime;
                };

            public:
                DebugLineRendererEcef(Rendering::Materials::IMaterial* material,
                                      const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                      int vertexBufferSize,
                                      float lineWidth);

                ~DebugLineRendererEcef();

                void SetLineWidth(float lineWidth);

                void DrawLine(const dv3& ecefPointA,
                        const dv3& ecefPointB,
                        const v4& color,
                        const float lifetime = 0.0f
                );
                
                void Update(float dt, const Camera::RenderCamera& renderCamera);
                
                void GenerateGeometry(const Camera::RenderCamera& renderCamera);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
                
                void SetDepthEnabled(const bool depthEnabled);

            private:
                std::vector<DebugLineEcef> m_drawData;
                
                DebugLineRenderable* m_pDebugLineRenderable;
            };
        }
    }
}


