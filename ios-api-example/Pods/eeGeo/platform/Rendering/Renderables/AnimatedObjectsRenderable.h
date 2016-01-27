// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BasicRenderable.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "AnimatedObjectsRenderer.h"
#include "GLState.h"
#include "EffectHandler.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            namespace TemporaryLegacySupport
            {
                class AnimatedObjectsRenderable : public BasicRenderable
                {
                public:
                    AnimatedObjectsRenderable
                    (
                     Rendering::LayerIds::Values layerId,
                     Rendering::Materials::IMaterial& material,
                     Eegeo::AnimatedObjects::AnimatedObjectsRenderer& animatedObjectsRenderer
                     )
                    : BasicRenderable(layerId, &material)
                    , m_animatedObjectsRenderer(animatedObjectsRenderer)
                    {
                    }
                    
                    void Render(Rendering::GLState& glState) const
                    {
                        glState.DepthTest.Enable();
                        m_animatedObjectsRenderer.Render(glState);
                        Eegeo::EffectHandler::Reset();
                    }
                    
                private:
                    Eegeo::AnimatedObjects::AnimatedObjectsRenderer& m_animatedObjectsRenderer;
                };
            }
        }
    }
}


