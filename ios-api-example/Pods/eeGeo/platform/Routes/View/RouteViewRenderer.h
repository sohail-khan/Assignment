// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRenderableFilter.h"
#include "Rendering.h"
#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewRenderer : Eegeo::NonCopyable, public Rendering::IRenderableFilter
            {
                const RouteViewRepository& m_routeViewRepository;
                const Rendering::EnvironmentFlatteningService& m_flatteningService;
                
                bool m_wireframe;
                bool m_enabled;
                bool m_disableDepth;
            public:
                RouteViewRenderer(const RouteViewRepository& routeViewRepository,
                                  const Rendering::EnvironmentFlatteningService& flatteningService);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
                
                bool IsEnabled() const;
                
                void ToggleEnabled();
                
                bool IsWireframe() const;
                
                void ToggleWireframe();
                
                void ToggleDepthDisabling();
                
                bool IsDepthDisabled() const;
            };
        }
    }
}
