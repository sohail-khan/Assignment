// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TextMaterial.h"
#include <string>
#include "Rendering.h"
#include "RoadNamesRenderable.h"
#include "RoadNamesFadeController.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            class RoadNamesMaterial : public Rendering::Materials::TextMaterial
            {
            public:
                RoadNamesMaterial(
                                   const Rendering::TMaterialId materialId,
                                   const std::string& name,
                                   Rendering::Shaders::TextShader& shader,
                                   Rendering::TTextureId textureId,
                                   const Resources::Roads::RoadNamesFadeController& fadeController
                                   )
                : Rendering::Materials::TextMaterial(materialId, name, shader, textureId, false, true)
                , m_fadeController(fadeController)
                {
                }
                
                void SetState(Rendering::GLState& glState) const
                {
                    TextMaterial::SetState(glState);
                    
                    const float fadeParam = m_fadeController.GetFadeParam();
                    
                    SetForegroundColour(v4(1, 1, 1, fadeParam));
                    SetShadowColour(v4(0, 0, 0, fadeParam));
                    m_shader.SetOutlineColour(v4(0, 0, 0, fadeParam));
                }
                
                void SetStatePerRenderable(const Rendering::RenderableBase* pRenderableBase, Rendering::GLState& glState) const
                {
                    Resources::Roads::RoadNamesRenderable* pRoadNamesRenderable = (Resources::Roads::RoadNamesRenderable*)(pRenderableBase);
                    
                    SetMVP(pRoadNamesRenderable->GetModelViewProjection());
                    SetScale(pRoadNamesRenderable->GetScale());
                }
                
            private:
                const Resources::Roads::RoadNamesFadeController& m_fadeController;
            };
        }
    }
}
