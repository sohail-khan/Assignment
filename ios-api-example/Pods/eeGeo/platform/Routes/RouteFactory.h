// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class RouteFactory : public Eegeo::NonCopyable
        {
            Clipping::RouteClippingService& m_routeClippingService;
            
        public:
            RouteFactory(Clipping::RouteClippingService& routeClippingService);
            
            Route* CreateRoute(const std::vector<RouteVertex>& routeVertices,
                               bool fittingToNavigationGraphEnabled);
            
            Route* CreateRoute(const Clipping::ClippedRoute& clippedRoute,
                               const std::vector<RouteVertex>& clippedRouteVertices,
                               bool fittingToNavigationGraphEnabled);
        };
    }
}
