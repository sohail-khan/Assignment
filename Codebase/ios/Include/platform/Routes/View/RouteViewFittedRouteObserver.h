// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "FittedRouteCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewFittedRouteObserver : public Eegeo::NonCopyable
            {
            public:
                RouteViewFittedRouteObserver(Fitting::FittedRouteRepository& fittedRouteRepository,
                                         RouteViewService& routeViewService);
                
                ~RouteViewFittedRouteObserver();
            private:
                Fitting::FittedRouteRepository& m_fittedRouteRepository;
                RouteViewService& m_routeViewService;
                
                Fitting::TFittedRouteCallback<RouteViewFittedRouteObserver> m_fittedRouteAddedCallback;
                Fitting::TFittedRouteCallback<RouteViewFittedRouteObserver> m_fittedRouteRemovedCallback;
                
                void HandleFittedRouteAdded(const Fitting::FittedRoute& fittedRoute);
                void HandleFittedRouteRemoved(const Fitting::FittedRoute& fittedRoute);
            };
        }
    }
}