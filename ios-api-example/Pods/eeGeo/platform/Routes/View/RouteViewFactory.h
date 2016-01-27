// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRouteViewFactory.h"
#include "Routes.h"
#include "Rendering.h"
#include "RouteRenderVertex.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewFactory : public IRouteViewFactory
            {
                RouteViewMaterial& m_routeViewMaterial;
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;

                RouteViewMeshFactory& m_routeViewMeshFactory;
                
                const float m_missingTerrainAlphaMultiplier;

                void CreateViewsFromMeshData(
                        const Fitting::FittedRoute& route,
                        const Style::RouteStyle& routeStyle,
                        const std::vector<RouteRenderVertex>& vertices,
                        const std::vector<u16>& indices,
                        std::vector<RouteView*>& out_views);
                
            public:
                RouteViewFactory(RouteViewMaterial& routeViewMaterial,
                                      Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                      RouteViewMeshFactory& routeViewMeshFactory,
                                      float missingTerrainAlphaMultiplier);
                
                ~RouteViewFactory();
                
                void CreateViews(const Fitting::FittedRoute& route,
                                 const Routes::Style::RouteStyle& routeStyle,
                                 std::vector<RouteView*>& out_views);
            };
        }
    }
}
