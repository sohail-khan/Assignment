// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BasicRenderable.h"
#include "Routes.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            namespace View
            {
                class RouteSimulationModelBinding
                {
                    const RouteSimulationSession& m_routeSimulationSession;
                    Rendering::Filters::SceneModelRenderableFilter& m_sceneModelRenderableFilter;
                    
                    bool m_enabled;
                    Rendering::SceneModels::SceneModel* m_pSceneModel;
                    Eegeo::m44 m_transform;
                    float m_alpha;
                    Rendering::LayerIds::Values m_layerId;
                    
                    dv3 m_cameraEcefLocation;
                    
                public:
                    RouteSimulationModelBinding(Rendering::LayerIds::Values layerId,
                                                const RouteSimulationSession& routeSimulationSession,
                                                Rendering::Filters::SceneModelRenderableFilter& sceneModelRenderableFilter);
                    ~RouteSimulationModelBinding();
                    
                    bool GetEnabled() const;
                    
                    void SetEnabled(bool enabled);
                    
                    void SetModelTransform(const Eegeo::m44& transform);
                    const m44& GetModelTransform() const;
                    
                    void SetModel(Rendering::SceneModels::SceneModel* pSceneModel);
                    const Rendering::SceneModels::SceneModel* GetModel() const;

                    void SetAlpha(float alpha);
                    float GetAlpha(void) const;
                    
                    void Update();
                };
            }
        }
    }
}
