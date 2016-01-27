// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Routes.h"
#include "Rendering.h"

namespace Eegeo
{
    class Node;
    
    namespace Routes
    {
        namespace Simulation
        {
            namespace View
            {
                class RouteSimulationViewService
                { 
                    RouteSimulationViewRepository& m_repository;
                    RouteSimulationViewFactory& m_factory;
                    
                public:
                    
                    RouteSimulationViewService(RouteSimulationViewRepository& repository,
                                               RouteSimulationViewFactory& factory);
                    
                    void Update();
            
                    RouteSimulationModelBinding* CreateBinding(const RouteSimulationSession& routeSimulationSession,
                                                               Rendering::SceneModels::SceneModel* pModel,
                                                               const Eegeo::m44& localTransform);
            
                    void DestroyBinding(RouteSimulationModelBinding* pBinding);
                };
            }
        }
    }
}
