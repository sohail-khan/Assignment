// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "VectorMath.h"
#include "Fonts.h"
#include "Rendering.h"
#include "Streaming.h"
#include "IRenderableFilter.h"
#include "DebugRendering.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace DebugRendering
    {
        namespace Renderers
        {
            class DebugTextRendererScreenSpace : public Rendering::IRenderableFilter
            {
                struct DebugTextEcef
                {
                    v2 LeftOrigin;
                    v4 Color;
                    std::string Text;
                    float Size;
                    float Lifetime;
                    Fonts::FontInstance* pFont;
                };
                
            public:
                DebugTextRendererScreenSpace(Rendering::Materials::IMaterial* material,
                                             const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                             int vertexBufferSize,
                                             int indexBufferSize,
                                             Fonts::FontInstance& font);
                
                ~DebugTextRendererScreenSpace();
                
                void DrawText(
                              const v2& leftOrigin,
                              const std::string text,
                              const float size,
                              const float lifetime = 0.0f
                              );
                
                void Update(float dt);
                
                void GenerateGeometry();
                
                void SetDepthEnabled(const bool depthEnabled);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
                
            private:
  
                void GenerateGeometryForSingleInstance(const DebugTextEcef& data);
                
                DebugTextRenderable* m_pDebugTextRenderable;
                
                Fonts::FontInstance& m_font;
                std::vector<DebugTextEcef> m_drawData;
            };
        }
    }
}