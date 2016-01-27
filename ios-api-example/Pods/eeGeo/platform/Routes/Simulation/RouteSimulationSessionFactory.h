// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSimulationSessionFactory : public Eegeo::NonCopyable
            {
                RouteSamplerFactory& m_routeSamplerFactory;
                
            public:
                RouteSimulationSessionFactory(RouteSamplerFactory& routeSamplerFactory);
                
                RouteSimulationSession* CreateSimulationSessionForRoute(const Route& route) const;
            };
        }
    }
}
