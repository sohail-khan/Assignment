// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PackedDiffuseShader.h"
#include "GLState.h"
#include "GlobalLighting.h"
#include "GlobalFogging.h"
#include "IDiffuseMaterial.h"
#include "LightmappedPackedDiffuseTransitionShader.h"
#include "LightmappedRenderable.h"
#include "TextureMinifyType.h"
#include "VectorMath.h"
#include "GLHelpers.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class LightmappedPackedDiffuseTransitionMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                LightmappedPackedDiffuseTransitionMaterial(
                                                 const TMaterialId materialId,
                                                 const std::string& name,
                                                 Shaders::LightmappedPackedDiffuseTransitionShader& shader,
                                                 const Lighting::GlobalLighting& lighting,
                                                 const Lighting::GlobalFogging& fogging,
                                                 TTextureId fromTextureId,
                                                 TTextureId toTextureId,
                                                 Rendering::TextureMinifyType textureMinifyType,
                                                 bool useAlternativeAmbient,
                                                 bool textureRepeat
                                                 )
                : m_id(materialId)
                , m_name(name)
                , m_shader(shader)
                , m_lighting(lighting)
                , m_fogging(fogging)
                , m_fromTextureId(fromTextureId)
                , m_toTextureId(toTextureId)
                , m_textureMinifyType(textureMinifyType)
                , m_useAlternativeAmbient(useAlternativeAmbient)
                , m_textureRepeat(textureRepeat)
                , m_lerpParam(0.f)
                {
                }
                
                ~LightmappedPackedDiffuseTransitionMaterial()
                {
                }
                
                bool IsUsingAlternativeAmbient() const { return m_useAlternativeAmbient; }
                void UseAlternativeAmbient(bool useAlternativeAmbient) { m_useAlternativeAmbient = useAlternativeAmbient; }
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetFromDiffuseTexture(TTextureId textureId) { m_fromTextureId = textureId; }
                TTextureId GetFromTextureId() const { return m_fromTextureId; }
                
                void SetToDiffuseTexture(TTextureId textureId) { m_toTextureId = textureId; }
                TTextureId GetToTextureId() const { return m_toTextureId; }
                
                void SetLerpParam(float t) { m_lerpParam = t; }
                float GetLerpParam() const { return m_lerpParam; }
                
                void SetState(Rendering::GLState& glState) const
                {
                    m_shader.Use(glState);
                    
                    glState.Blend.Disable();
                    glState.DepthTest.Enable();
                    
                    const Eegeo::m44 &lightColors = m_lighting.GetColors(m_useAlternativeAmbient);
                    m_shader.SetLightColors(lightColors);
                    m_shader.SetLightmapColour(m_lighting.GetNightLightmapColour());
                    m_shader.SetLightmapIntensity(m_lighting.GetNightGlowLightmapIntensity());
                    v4 ambientColorRow = lightColors.GetRow(3);
                    
                    Lighting::GlobalFoggingUniformValues fogValues;
                    m_fogging.GetUniformValues(fogValues);
                    m_shader.SetFogUniforms(fogValues);
                    
                    m_shader.SetAmbientColor(v3(ambientColorRow.GetX(), ambientColorRow.GetY(), ambientColorRow.GetZ()));
                    m_shader.SetLerpParam(m_lerpParam);

                    Helpers::GLHelpers::BindTexture2D(glState, m_shader.GetFromDiffuseSamplerId(), m_fromTextureId, m_textureMinifyType, m_textureRepeat);
                    Helpers::GLHelpers::BindTexture2D(glState, m_shader.GetToDiffuseSamplerId(), m_toTextureId, m_textureMinifyType, m_textureRepeat);
                }
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const
                {
                    Rendering::Renderables::LightmappedRenderable* lightmappedRenderable = (Rendering::Renderables::LightmappedRenderable*)(renderableBase);
                    BindLightmapTexture(glState, lightmappedRenderable->GetLightmapTextureId());
                    m_shader.SetMVP(lightmappedRenderable->GetModelViewProjection());
                    m_shader.SetUVBounds(lightmappedRenderable->GetUVBoundsMin(), lightmappedRenderable->GetUVBoundsMax());
                    m_shader.SetPositionBounds(lightmappedRenderable->GetPositionBoundsMin(), lightmappedRenderable->GetPositionBoundsMax());
                    m_shader.SetCameraRelativeOrigin(lightmappedRenderable->GetCameraRelativeModelOrigin());
                }
                
            protected:
                void BindLightmapTexture(Rendering::GLState& glState, TTextureId lightmapId) const
                {
                    Helpers::GLHelpers::BindTexture2D(glState, m_shader.GetLightmapSamplerId(), lightmapId, Rendering::TextureMinify_Nearest, false);
                }
                
                const TMaterialId m_id;
                const std::string m_name;
                const Shaders::LightmappedPackedDiffuseTransitionShader& m_shader;
                const Lighting::GlobalLighting& m_lighting;
                const Lighting::GlobalFogging& m_fogging;
                TTextureId m_fromTextureId;
                TTextureId m_toTextureId;
                Rendering::TextureMinifyType m_textureMinifyType;
                bool m_textureRepeat;
                bool m_useAlternativeAmbient;
                float m_lerpParam;
            };
        }
    }
}
