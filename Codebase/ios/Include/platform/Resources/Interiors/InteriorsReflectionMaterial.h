// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once


#include "Interiors.h"
#include "InteriorsMaterialBase.h"
#include "TextureMinifyType.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMath.h"


#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {

            class InteriorsReflectionMaterial : public InteriorsMaterialBase
            {
            public:
                InteriorsReflectionMaterial(const Rendering::TMaterialId materialId,
                                                 const std::string& name,
                                                 const Lighting::GlobalLighting& lighting,
                                                 IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                                 bool useAlternativeAmbient,
                                                 bool isTranslucent,
                                                 const v4& diffuseColor,
                                                 const InteriorsDiffuseSpecularShader& shader,
                                                 Rendering::TTextureId diffuseTextureId,
                                                 Rendering::TextureMinifyType textureMinifyType,
                                                 bool textureRepeat,
                                                 const v3& specularColor,
                                                 float specularPower,
                                                 float specularModulateTexture,
                                                 float specularityFromTextureLuminance,
                                                 const v4& reflectionPlaneTangentSpace);
                

                
                ~InteriorsReflectionMaterial();
                
                const Eegeo::Rendering:: Shader& GetShader() const;
                
                void OnAssignedToRenderable(Rendering::Renderables::InteriorRenderable& renderable);
                
                void SetState(Eegeo::Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Eegeo::Rendering::RenderableBase* renderableBase, Eegeo::Rendering::GLState& glState) const;
                
            private:
                const InteriorsDiffuseSpecularShader& m_shader;
                const Rendering::TTextureId m_diffuseTextureId;
                const Rendering::TextureMinifyType m_textureMinifyType;
                const bool m_textureRepeat;
                const v3 m_specularColor;
                const float m_specularPower;
                const float m_specularModulateTexture;
                const float m_specularityFromTextureLuminance;
                const v4 m_reflectionPlaneTangentSpace;
            };
        }
    }
}