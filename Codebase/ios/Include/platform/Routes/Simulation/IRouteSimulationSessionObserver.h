// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class IRouteSimulationSessionObserver
            {
            public:
                virtual void OnLinkReached(const RouteSimulationSession& session) const = 0;
                
                virtual ~IRouteSimulationSessionObserver() { };
            };
        }
    }
}
