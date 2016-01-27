//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "IRenderableFilter.h"
#include "Interiors.h"
#include "Rendering.h"
#include "CullingVolumeVisibilityUpdater.h"

#include <vector>
#include <deque>
#include <iterator>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Filters
        {
            class InteriorsRenderableFilter : public IRenderableFilter
            {
            public:
                InteriorsRenderableFilter(Resources::Interiors::IInteriorController& interiorController,
                                          Renderables::WorldMeshRenderable& quadRenderable,
                                          const Rendering::EnvironmentFlatteningService& environmentFlatteningService);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
                
            private:

                typedef std::deque<std::pair<Rendering::Renderables::InteriorRenderable*, float> > TRenderableDepthList;
                typedef std::deque<Resources::Interiors::InteriorsStencilMirrorClearRenderable*> TStencilClearRenderableList;
                void EnqueueRenderablesForFloorCells(const std::vector<Resources::Interiors::InteriorsFloorCell*>& floorCells, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue, std::back_insert_iterator<TRenderableDepthList> translucentRenderables, std::back_insert_iterator<TStencilClearRenderableList> stencilClearRenderables);
                void EnqueueRenderablesForInteriorsFloorCell(const Resources::Interiors::InteriorsFloorCell& interiorsFloorCell, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue, std::back_insert_iterator<TRenderableDepthList> translucentRenderables, std::back_insert_iterator<TStencilClearRenderableList> stencilClearRenderables);
                void EnqueueInteriorFloorRenderable(Rendering::Renderables::InteriorFloorRenderable& interiorFloorRenderable, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue, std::back_insert_iterator<TRenderableDepthList> translucentRenderables, std::back_insert_iterator<TStencilClearRenderableList> stencilClearRenderables);
                void EnqueueInteriorHighlightRenderable(Rendering::Renderables::InteriorHighlightRenderable& interiorHighlightRenderable, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue, std::back_insert_iterator<TRenderableDepthList> translucentRenderables);
                void EnqueueInstancedInteriorRenderable(Rendering::Renderables::InstancedInteriorFloorRenderable& instancedRenderable, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue, std::back_insert_iterator<TRenderableDepthList> translucentRenderables);
                void EnqueueDepthSortedInteriorFloorRenderables(TRenderableDepthList::iterator first, TRenderableDepthList::iterator last, RenderQueue& renderQueue) const;
                
                Resources::Interiors::IInteriorController& m_controller;
                Renderables::WorldMeshRenderable& m_quadRenderable;
                const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                Culling::CullingVolumeVisibilityUpdater m_cullingVolumeVisibilityUpdater;
                
                TRenderableDepthList m_translucentRenderables;
                TStencilClearRenderableList m_stencilClearRenderables;
            };
        }
    }
}