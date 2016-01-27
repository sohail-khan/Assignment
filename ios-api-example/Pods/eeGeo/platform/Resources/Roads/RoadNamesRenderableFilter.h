// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRenderableFilter.h"
#include "Rendering.h"
#include "Roads.h"
#include "RoadNamesFadeController.h"
#include "VectorMath.h"
#include "EnvironmentFlatteningService.h"
#include "RenderContext.h"
#include "ISceneElementSource.h"
#include "RoadNamesRenderable.h"
#include "SceneElement.h"
#include "RenderQueue.h"
#include "RenderCamera.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            const float FadeOffsetHeight = 5.0f;

            class RoadNamesRenderableFilter : protected Eegeo::NonCopyable, public Rendering::IRenderableFilter
            {
            public:
                RoadNamesRenderableFilter(
                                          const Rendering::Scene::ISceneElementSource<RoadNamesRenderable>& sceneElementsSource,
                                          const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                          const Resources::Roads::RoadNamesFadeController& roadNamesFadeController
                                          )
                : m_sceneElementsSource(sceneElementsSource)
                , m_environmentFlatteningService(environmentFlatteningService)
                , m_roadNamesFadeController(roadNamesFadeController)
                , m_enabled(true)
                {
                }
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue)
                {
                    if(!m_enabled)
                        return;

                    const float fadeParam = m_roadNamesFadeController.GetFadeParam();
                    
                    if(fadeParam > 0.0f)
                    {
                        const float environmentFlatteningScale = m_environmentFlatteningService.GetCurrentScale();
                        const float fadeOffsetMagnitude = FadeOffsetHeight * (1.0f - fadeParam);
                        
                        const Camera::RenderCamera& renderCamera = renderContext.GetRenderCamera();
                        
                        const dv3& ecefCameraPosition = renderCamera.GetEcefLocation();
                        const m44& viewProjection = renderCamera.GetViewProjectionMatrix();
                        
                        typedef Rendering::Scene::SceneElement<RoadNamesRenderable> TSceneElement;
                        typedef std::vector<TSceneElement*> TSceneElementPtrVec;
                        TSceneElementPtrVec sceneElements;
                        m_sceneElementsSource.GetSceneElements(sceneElements);
                        
                        for (TSceneElementPtrVec::const_iterator it = sceneElements.begin(); it != sceneElements.end(); ++it)
                        {
                            const TSceneElement* pSceneElement = (*it);
                            
                            if(pSceneElement->IsInSceneGraph())
                            {
                                RoadNamesRenderable& renderable = pSceneElement->GetResource();
                            
                                Eegeo::v3 up = renderable.GetEcefPosition().ToSingle().Norm();
                            
                                v3 flattening = up * (environmentFlatteningScale - 1.f);
                                renderable.SetScale(flattening);
                            
                                renderable.UpdateMVP(ecefCameraPosition, viewProjection, up, environmentFlatteningScale, fadeOffsetMagnitude);
                            
                                renderQueue.EnqueueRenderable(&renderable);
                            }
                        }
                    }
                }
                void SetEnabled(bool enabled) { m_enabled = enabled;}
                
            private:
                const Rendering::Scene::ISceneElementSource<RoadNamesRenderable>& m_sceneElementsSource;
                const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                const Resources::Roads::RoadNamesFadeController& m_roadNamesFadeController;
                bool m_enabled;
            };
        }
    }
}
