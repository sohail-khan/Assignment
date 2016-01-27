// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSimulationService : public Eegeo::NonCopyable
            {
                RouteSimulationSessionFactory& m_routeSimulationSessionFactory;
                RouteSimulationSessionRepository& m_routeSimulationSessionRepository;
                
            public:
                RouteSimulationService(RouteSimulationSessionFactory& routeSimulationSessionFactory,
                                       RouteSimulationSessionRepository& routeSimulationSessionRepository);
                
                RouteSimulationSession* BeginRouteSimulationSession(const Route& route);
                
                void EndRouteSimulationSession(const RouteSimulationSession* session);
                
                void EndAllSimulationSessionsForRoute(const Route *pRoute);
                
                void HandleFittedRouteChanged(const Fitting::FittedRoute& fittedRoute);

                
                void Update(float dt);
                
            private:
                void GetSessionsForRoute(const Route* route, std::vector<RouteSimulationSession*>& out_sessionsForRoute) const;
            };
        }
    }
}
