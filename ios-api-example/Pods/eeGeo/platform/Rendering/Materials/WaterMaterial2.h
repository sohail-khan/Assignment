// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "IdTypes.h"
#include "Lighting.h"
#include "Rendering.h"
#include "WaterShader.h"
#include "TextureMinifyType.h"
#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class WaterMaterial2 : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                WaterMaterial2(
                                      const TMaterialId materialId,
                                      const std::string& name,
                                      Shaders::WaterShader& shader,
                                      const Lighting::GlobalLighting& lighting,
                                      const Lighting::GlobalFogging& fogging,
                                      TTextureId diffuseTextureId,
                                      TTextureId normalMapTextureId,
                                      TTextureId reflectionTextureId,
                                      Rendering::TextureMinifyType textureMinifyType,
                                      bool useAlternativeAmbient,
                                      bool textureRepeat,
                                      Eegeo::v2 animationScaleUV,
                                      Eegeo::v2 animationWrapUV
                               );
                
                bool IsUsingAlternativeAmbient() const { return m_useAlternativeAmbient; }
                void UseAlternativeAmbient(bool useAlternativeAmbient) { m_useAlternativeAmbient = useAlternativeAmbient; }
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetDiffuseTexture(TTextureId textureId) { m_diffuseTextureId = textureId; }
                TTextureId GetDiffuseTextureId() const { return m_diffuseTextureId; }

                void SetNormalMapTexture(TTextureId textureId) { m_normalMapTextureId = textureId; }
                TTextureId GetNormalMapTextureId() const { return m_normalMapTextureId; }

                void SetReflectionTexture(TTextureId textureId) { m_reflectionMapTextureId = textureId; }
                TTextureId GetReflectionTextureId() const { return m_reflectionMapTextureId; }
                
                void UpdateMaterial(float deltaTime, const dv3& ecefCameraPosition);
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::WaterShader& m_shader;
                const Lighting::GlobalLighting& m_lighting;
                const Lighting::GlobalFogging& m_fogging;
                TTextureId m_diffuseTextureId;
                TTextureId m_normalMapTextureId;
                TTextureId m_reflectionMapTextureId;
                Rendering::TextureMinifyType m_textureMinifyType;
                bool m_textureRepeat;
                bool m_useAlternativeAmbient;
                float m_altitudeScale;
                Eegeo::v2 m_animationScaleUV;
                Eegeo::v2 m_animationWrapUV;
                Eegeo::v4 m_animationStateUV;
            };
        }
    }
}