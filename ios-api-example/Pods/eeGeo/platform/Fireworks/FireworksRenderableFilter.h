// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IRenderableFilter.h"
#include "Rendering.h"
#include "Fireworks.h"
#include "Types.h"

namespace Eegeo
{
    namespace Fireworks
    {
        class FireworksRenderableFilter : public Rendering::IRenderableFilter, NonCopyable
        {
        public:
            
            FireworksRenderableFilter(Rendering::Renderables::BatchedSpriteRenderable& batchedSpriteRenderable);
            
            void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
            
        private:
            
            Rendering::Renderables::BatchedSpriteRenderable& m_batchedSpriteRenderable;
        };
    }
}