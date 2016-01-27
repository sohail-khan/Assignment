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
            namespace View
            {
                class RouteSimulationViewRepository : public Eegeo::NonCopyable
                {
                private:
                    std::vector<RouteSimulationModelBinding*> m_viewBindings;
                    
                public:
                    void AddViewBinding(RouteSimulationModelBinding* pBinding);
                    
                    void RemoveViewBinding(RouteSimulationModelBinding* pBinding);
                    
                    const std::vector<RouteSimulationModelBinding*>& GetViewBindings() const;
                    
                };
            }
        }
    }
}
