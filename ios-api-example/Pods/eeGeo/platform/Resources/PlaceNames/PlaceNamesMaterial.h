// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "TextMaterial.h"
#include "IdTypes.h"
#include "PlaceNameRenderable.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNamesMaterial : public Rendering::Materials::TextMaterial
            {
            public:
                PlaceNamesMaterial(
                                   const Rendering::TMaterialId materialId,
                                   const std::string& name,
                                   Rendering::Shaders::TextShader& shader,
                                   Rendering::TTextureId textureId
                                   )
                : Rendering::Materials::TextMaterial(materialId, name, shader, textureId, true, false)
                {
                }
                
                void SetStatePerRenderable(const Rendering::RenderableBase* pRenderableBase, Rendering::GLState& glState) const
                {
                    Resources::PlaceNames::PlaceNameRenderable* pPlaceNameRenderable = (Resources::PlaceNames::PlaceNameRenderable*)(pRenderableBase);
                    
                    SetMVP(pPlaceNameRenderable->GetModelViewProjection());
                    SetScale(pPlaceNameRenderable->GetScale());
                    SetForegroundColour(pPlaceNameRenderable->GetForegroundColour());
                    SetShadowColour(pPlaceNameRenderable->GetShadowColour());
                    m_shader.SetOutlineColour(pPlaceNameRenderable->GetOutlineColour());
                }
            };
        }
    }
}
