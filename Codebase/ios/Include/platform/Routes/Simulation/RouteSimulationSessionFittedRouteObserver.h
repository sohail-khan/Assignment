// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "FittedRouteCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSimulationSessionFittedRouteObserver : public Eegeo::NonCopyable
            {
                Fitting::FittedRouteRepository& m_fittedRouteRepository;
                RouteSimulationService& m_routeSimulationService;
                
                Fitting::TFittedRouteCallback<RouteSimulationSessionFittedRouteObserver> m_addedCallback;
                Fitting::TFittedRouteCallback<RouteSimulationSessionFittedRouteObserver> m_removalCallback;
                
                void HandleFittedRouteAdded(const Fitting::FittedRoute& fittedRoute);
                void HandleFittedRouteRemoved(const Fitting::FittedRoute& fittedRoute);
                
            public:
                RouteSimulationSessionFittedRouteObserver(Fitting::FittedRouteRepository& fittedRouteRepository,
                                                          RouteSimulationService& routeSimulationService);
                
                ~RouteSimulationSessionFittedRouteObserver();
            };
        }
    }
}
