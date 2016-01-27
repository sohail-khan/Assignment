//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "StencilAreaRenderable.h"
#include "SimpleRenderFilter.h"
#include "StencilAreaView.h"
#include "WorldMeshRenderable.h"
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            class StencilAreaRenderer : public Rendering::IRenderableFilter, private Eegeo::NonCopyable
            {
            public:
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
                
                void AddPaletteFullScreenQuad(Rendering::Renderables::WorldMeshRenderable& quad);
                
                void RemovePaletteFullScreenQuad(Rendering::Renderables::WorldMeshRenderable& quad);
                
                void AddView(StencilAreaView& view);
                
                void RemoveView(StencilAreaView& view);
                
                void Clear();
                
            private:
                typedef std::vector<Rendering::Renderables::WorldMeshRenderable*> TQuads;
                
                Rendering::Filters::SimpleRenderFilter<StencilAreaView> m_simpleRenderFilter;
                TQuads m_stencilQuads;
            };
        }
    }
}