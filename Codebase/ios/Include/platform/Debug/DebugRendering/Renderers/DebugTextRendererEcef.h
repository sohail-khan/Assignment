// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "VectorMath.h"
#include "Fonts.h"
#include "Rendering.h"
#include "Streaming.h"
#include "DynamicBuffer.h"
#include "AllVertexTypes.h"
#include "Camera.h"
#include "IMaterial.h"
#include "DebugTextRenderable.h"
#include "IRenderableFilter.h"

#include <string>

namespace Eegeo
{
    namespace DebugRendering
    {
        namespace Renderers
        {
            class DebugTextRendererEcef : public Rendering::IRenderableFilter
            {
                struct DebugTextEcef
                {
                    dv3 Origin;
                    v4 Color;
                    std::string Text;
                    float Size;
                    float Lifetime;
                    Fonts::FontInstance* pFont;
                };

            public:
                DebugTextRendererEcef(Rendering::Materials::IMaterial* material,
                                      const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                      int vertexBufferSize,
                                      int indexBufferSize,
                                      Fonts::FontInstance& font);

                ~DebugTextRendererEcef();

                void DrawText(
                        const dv3& ecefCenter,
                        const std::string text,
                        const float size,
                        const float lifetime = 0.0f
                );

                void Update(float dt, const Camera::RenderCamera& renderCamera);
                
                void GenerateGeometry(const Camera::RenderCamera& renderCamera);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
                
                void SetDepthEnabled(const bool depthEnabled);

            private:
                
                void GenerateGeometryForSingleInstance(const DebugTextEcef& data, const Camera::RenderCamera& renderCamera);

                DebugTextRenderable* m_pDebugTextRenderable;
     
                Fonts::FontInstance& m_font;
                std::vector<DebugTextEcef> m_drawData;
            };
        }
    }
}