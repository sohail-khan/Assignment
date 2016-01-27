// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "IRenderableFilter.h"
#include "Rendering.h"
#include "Collision.h"
#include "CollisionVisualization.h"
#include <deque>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class CollisionVisualizationRenderer : public Eegeo::Rendering::IRenderableFilter, private Eegeo::NonCopyable
        {
        public:
            CollisionVisualizationRenderer(Eegeo::Rendering::RenderableFilters& platformRenderableFilters,
                                           Eegeo::Rendering::EnvironmentFlatteningService& environmentFlatteningService);
            virtual ~CollisionVisualizationRenderer();
            
            void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
            void Submit(CollisionVisualizationRenderable& renderable);
            
        private:
            std::deque<CollisionVisualizationRenderable*> m_renderables;
            Eegeo::Rendering::RenderableFilters& m_platformRenderableFilters;
            Eegeo::Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
        };
    }
}