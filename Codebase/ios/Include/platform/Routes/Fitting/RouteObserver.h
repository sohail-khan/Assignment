// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "RouteCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class RouteObserver : public Eegeo::NonCopyable
            {
                RouteRepository& m_routeRepository;
                RouteFittingService& m_routeFittingService;
                NavGraphFittingInfoService& m_navGraphFittingInfoService;
                
                TRouteCallback<RouteObserver> m_addedCallback;
                TRouteCallback<RouteObserver> m_removalCallback;
                
                void HandleRouteAdded(const Route* route);
                void HandleRouteRemoved(const Route* route);
                
            public:
                RouteObserver(RouteRepository& routeRepository,
                              RouteFittingService& routeFittingService,
                              NavGraphFittingInfoService& navGraphFittingInfoService);
                
                ~RouteObserver();
            };
        }
    }
}
