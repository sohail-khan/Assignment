// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class RouteService : public Eegeo::NonCopyable
        {
            RouteRepository& m_routeRepository;
            RouteStyleRepository& m_routeStyleRepository;
            View::RouteViewFactoryRepository& m_routeViewFactoryRepository;
            RouteFactory& m_routeFactory;
            View::IRouteViewFactory& m_defaultRouteViewFactory;
            
            void AddRoute(const Route& route, const Style::RouteStyle& routeStyle, View::IRouteViewFactory* pViewFactory);
        
        public:
            RouteService(RouteRepository& routeRepository,
                         RouteStyleRepository& routeStyleRepository,
                         View::RouteViewFactoryRepository& routeViewFactoryRepository,
                         RouteFactory& routeFactory,
                         View::IRouteViewFactory& defaultRouteViewFactory
                         );

            Route* CreateRoute(const std::vector<RouteVertex>& points,
                               const Style::RouteStyle& routeStyle,
                               bool fittingToNavigationGraphEnabled
                               );
            
            Route* CreateRoute(const std::vector<RouteVertex>& points,
                               const Style::RouteStyle& routeStyle,
                               bool fittingToNavigationGraphEnabled,
                               View::IRouteViewFactory* viewFactory
                               );
            
            Route* CreateRoute(const Clipping::ClippedRoute& clippedRoute,
                               const std::vector<RouteVertex>& clippedRouteVertices,
                               const Style::RouteStyle& routeStyle,
                               bool fittingToNavigationGraphEnabled
                               );
            
            Route* CreateRoute(const Clipping::ClippedRoute& clippedRoute,
                               const std::vector<RouteVertex>& clippedRouteVertices,
                               const Style::RouteStyle& routeStyle,
                               bool fittingToNavigationGraphEnabled,
                               View::IRouteViewFactory* viewFactory
                               );
            
            void SetRouteStyle(const Route* pRoute, Style::RouteStyle routeStyle);
            
            void RegenerateRoute(const Route* pRoute);
            
            void DestroyRoute(const Route* routeToDestroy);
            
            void DestroyAllRoutes();
        };
    }
}