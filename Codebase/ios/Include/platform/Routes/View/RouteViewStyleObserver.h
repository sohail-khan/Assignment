// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "RouteViewStyleCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewStyleObserver
            {
            private:
                RouteStyleRepository& m_routeStyleRepository;
                const Fitting::FittedRouteRepository& m_fittedRouteRepository;
                RouteViewService& m_routeViewService;
                TRouteViewStyleCallback<RouteViewStyleObserver> m_styleChangedCallback;
                
                void HandleRouteStyleChanged(const Route* pRoute, const Style::RouteStyle& routeStyle);

            public:
                RouteViewStyleObserver(RouteStyleRepository& routeStyleRepository,
                                       const Fitting::FittedRouteRepository& fittedRouteRepository,
                                       RouteViewService& routeViewService);
            };
        }
    }
}
