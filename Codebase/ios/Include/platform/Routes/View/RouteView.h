// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Streaming.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteView : protected Eegeo::NonCopyable
            {
            public:

                
                RouteView(RouteViewRenderable* renderable,
                          
                          const Style::Thickness::IRouteThicknessPolicy& thicknessPolicy,
                          const Fitting::FittedRoute& fittedRoute,
                          bool shouldFlatten);
                
                ~RouteView();
                
                RouteViewRenderable* GetRenderable() const { return m_renderable; }
                
                const Route* GetRoute() const;

                const Streaming::MortonKey& GetKey() const;
                
                void Update(const Eegeo::Rendering::RenderContext& renderContext,
                            const Rendering::EnvironmentFlatteningService& flatteningService,
                            bool depthTestEnabled,
                            bool wireframe);

                size_t GetNumTriangles() const;
            private:
                const Style::Thickness::IRouteThicknessPolicy& m_thicknessPolicy;
                const Fitting::FittedRoute& m_fittedRoute;
                
                RouteViewRenderable* m_renderable;
                bool m_shouldFlatten;
                
                float ComputeAltitudeFade();
            };
        }
    }
}
