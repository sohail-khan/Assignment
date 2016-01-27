// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "RouteCallback.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSimulationRouteObserver : public Eegeo::NonCopyable
            {
                RouteRepository& m_routeRepository;
                RouteSimulationService& m_routeSimulationService;
                
                TRouteCallback<RouteSimulationRouteObserver> m_addedCallback;
                TRouteCallback<RouteSimulationRouteObserver> m_removedCallback;
                
                void HandleRouteAdded(const Route* route);
                void HandleRouteRemoved(const Route* route);
                
            public:
                RouteSimulationRouteObserver(RouteRepository& routeRepository,
                                             RouteSimulationService& routeSimulationService);
                
                ~RouteSimulationRouteObserver();

            };
        }
    }
}