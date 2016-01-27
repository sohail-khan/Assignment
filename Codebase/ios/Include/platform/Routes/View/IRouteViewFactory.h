// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class IRouteViewFactory
            {
            public:
                virtual ~IRouteViewFactory() {}

                virtual void CreateViews(
                        const Fitting::FittedRoute& route,
                        const Routes::Style::RouteStyle& routeStyle,
                        std::vector<RouteView*>& out_views) = 0;
            };
        }
    }
}
