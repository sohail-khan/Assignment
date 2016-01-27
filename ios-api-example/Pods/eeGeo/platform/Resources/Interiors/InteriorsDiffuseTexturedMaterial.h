// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "InteriorsMaterialBase.h"
#include "PackedDiffuseMaterial.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "Lighting.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsDiffuseTexturedMaterial : public InteriorsMaterialBase
            {
            public:
                InteriorsDiffuseTexturedMaterial(
                                                 const Rendering::TMaterialId materialId,
                                                 const std::string& name,
                                                 const Lighting::GlobalLighting& lighting,
                                                 IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                                 bool useAlternativeAmbient,
                                                 bool isTranslucent,
                                                 const v4& diffuseColor,
                                                 const InteriorsDiffuseTexturedShader& shader,
                                                 Rendering::TTextureId diffuseTextureId,
                                                 Rendering::TextureMinifyType textureMinifyType,
                                                 bool textureRepeat);
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;

                const Rendering::Shader& GetShader() const;
            private:
                const InteriorsDiffuseTexturedShader& m_shader;
                const Rendering::TTextureId m_diffuseTextureId;
                const Rendering::TextureMinifyType m_textureMinifyType;
                const bool m_textureRepeat;
            };
        }
    }
}