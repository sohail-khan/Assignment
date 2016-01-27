// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSimulationSessionRepository : public Eegeo::NonCopyable
            {
            public:
                void AddSession(RouteSimulationSession* pSession);
                
                void RemoveSession(const RouteSimulationSession* pSession);
                
                std::vector<RouteSimulationSession*> GetSessions();

                void RegisterSessionRemovedCallback(IRouteSimulationSessionCallback* callback);
                void UnregisterSessionRemovedCallback(IRouteSimulationSessionCallback* callback);

            private:
                std::vector<RouteSimulationSession*> m_sessions;

                std::vector<IRouteSimulationSessionCallback*> m_sessionRemovedCallbacks;
                
                void FireCallbacks(std::vector<IRouteSimulationSessionCallback*>& callbacks, const RouteSimulationSession* session);
            };
        }
    }
}