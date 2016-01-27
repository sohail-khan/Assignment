// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMathDecl.h"
#include "LayerIds.h"
#include "Routes.h"

namespace Eegeo
{
    class Node;
    
    namespace Routes
    {
        namespace Simulation
        {
            namespace View
            {
                class RouteSimulationViewFactory : public Eegeo::NonCopyable
                {
                    Rendering::Filters::SceneModelRenderableFilter& m_sceneModelRenderableFilter;
                    Rendering::LayerIds::Values m_renderLayerId;
                    
                public:
                    RouteSimulationViewFactory(Rendering::Filters::SceneModelRenderableFilter& sceneModelRenderableFilter,
                                               Rendering::LayerIds::Values renderLayerId);
                    
                    RouteSimulationModelBinding*
                    CreateRouteSimulationSessionModelBinding(const RouteSimulationSession& routeSimulationSession,
                                                             Rendering::SceneModels::SceneModel* pModel,
                                                             const Eegeo::m44& localTransform);
                };
            }
        }
    }
}
