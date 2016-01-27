// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

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
            
            class InteriorsStencilMirrorMaterial : public InteriorsMaterialBase
            {
            public:
                InteriorsStencilMirrorMaterial(const Rendering::TMaterialId materialId,
                                            const std::string& name,
                                            const Lighting::GlobalLighting& lighting,
                                            IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                            bool useAlternativeAmbient,
                                            const v4& diffuseColor,
                                            const InteriorsStencilMirrorShader& shader,
                                            Rendering::TTextureId diffuseTextureId,
                                            Rendering::TextureMinifyType textureMinifyType,
                                            bool textureRepeat,
                                            const v3& mirrorClearColor,
                                            float fresnelBias,
                                            float fresnelScale,
                                            float fresnelPower,
                                            float viewOffsetScale);
                
                
                
                ~InteriorsStencilMirrorMaterial();
                
                const Eegeo::Rendering:: Shader& GetShader() const;
                
                void OnAssignedToRenderable(Rendering::Renderables::InteriorRenderable& renderable);
                
                void SetState(Eegeo::Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Eegeo::Rendering::RenderableBase* renderableBase, Eegeo::Rendering::GLState& glState) const;
                
            private:
                const InteriorsStencilMirrorShader& m_shader;
                const Rendering::TTextureId m_diffuseTextureId;
                const Rendering::TextureMinifyType m_textureMinifyType;
                const bool m_textureRepeat;
                const v3 m_mirrorClearColor;
                const float m_fresnelBias;
                const float m_fresnelScale;
                const float m_fresnelPower;
                const float m_viewOffsetScale;

            };
        }
    }
}