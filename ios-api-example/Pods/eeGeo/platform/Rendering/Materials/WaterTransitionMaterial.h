// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Lighting.h"
#include "WaterTransitionShader.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "TextureMinifyType.h"
#include "VectorMath.h"
#include "GLState.h"
#include "MathsHelpers.h"
#include "GlobalFogging.h"
#include "GlobalLighting.h"
#include "WaterRenderable.h"
#include "GLHelpers.h"
#include "EarthConstants.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class WaterTransitionMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                WaterTransitionMaterial(
                              const TMaterialId materialId,
                              const std::string& name,
                              Shaders::WaterTransitionShader& shader,
                              const Lighting::GlobalLighting& lighting,
                              const Lighting::GlobalFogging& fogging,
                              TTextureId fromDiffuseTextureId,
                              TTextureId toDiffuseTextureId,
                              TTextureId normalMapTextureId,
                              TTextureId fromReflectionTextureId,
                              TTextureId toReflectionTextureId,
                              Rendering::TextureMinifyType textureMinifyType,
                              bool useAlternativeAmbient,
                              bool textureRepeat,
                              Eegeo::v2 animationScaleUV,
                              Eegeo::v2 animationWrapUV
                              )
                : m_id(materialId)
                , m_name(name)
                , m_shader(shader)
                , m_lighting(lighting)
                , m_fogging(fogging)
                , m_fromDiffuseTextureId(fromDiffuseTextureId)
                , m_toDiffuseTextureId(toDiffuseTextureId)
                , m_normalMapTextureId(normalMapTextureId)
                , m_fromReflectionMapTextureId(fromReflectionTextureId)
                , m_toReflectionMapTextureId(toReflectionTextureId)
                , m_textureMinifyType(textureMinifyType)
                , m_textureRepeat(textureRepeat)
                , m_useAlternativeAmbient(useAlternativeAmbient)
                , m_animationScaleUV(animationScaleUV)
                , m_animationWrapUV(animationWrapUV)
                , m_animationStateUV(0,0,1,1)
                , m_altitudeScale(0.f)
                , m_lerpParam(0.f)
                {
                }
                
                bool IsUsingAlternativeAmbient() const { return m_useAlternativeAmbient; }
                void UseAlternativeAmbient(bool useAlternativeAmbient) { m_useAlternativeAmbient = useAlternativeAmbient; }
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetFromDiffuseTexture(TTextureId textureId) { m_fromDiffuseTextureId = textureId; }
                TTextureId GetFromDiffuseTextureId() const { return m_fromDiffuseTextureId; }

                void SetToDiffuseTexture(TTextureId textureId) { m_toDiffuseTextureId = textureId; }
                TTextureId GetToDiffuseTextureId() const { return m_toDiffuseTextureId; }

                void SetNormalMapTexture(TTextureId textureId) { m_normalMapTextureId = textureId; }
                TTextureId GetNormalMapTextureId() const { return m_normalMapTextureId; }
                
                void SetFromReflectionTexture(TTextureId textureId) { m_fromReflectionMapTextureId = textureId; }
                TTextureId GetFromReflectionTextureId() const { return m_fromReflectionMapTextureId; }

                void SetToReflectionTexture(TTextureId textureId) { m_toReflectionMapTextureId = textureId; }
                TTextureId GetToReflectionTextureId() const { return m_toReflectionMapTextureId; }

                void SetLerpParam(float t) { m_lerpParam = t; }
                float GetLerpParam() const { return m_lerpParam; }

                void UpdateMaterial(float deltaTime, const dv3& ecefCameraPosition)
                {
                    // TODO: Remove dry fail.
                    float altitude = (float)(ecefCameraPosition.Length() - Space::EarthConstants::Radius);
                    const float MaxEnvMapBlend = 0.5f;
                    const float EnvMapBlendDelta = -0.5f;
                    const float MaxEnvMapVisible = 5000.0f;
                    altitude = Clamp(altitude, 0.0f, MaxEnvMapVisible);
                    m_altitudeScale = Helpers::MathsHelpers::PennerQuadraticEaseOut(altitude,
                                                                                    MaxEnvMapBlend,
                                                                                    EnvMapBlendDelta,
                                                                                    MaxEnvMapVisible);
                    
                    m_animationStateUV.SetX(m_animationStateUV.GetX() + deltaTime * m_animationScaleUV.GetX());
                    m_animationStateUV.SetY(m_animationStateUV.GetY() + deltaTime * m_animationScaleUV.GetY());
                    
                    if(m_animationStateUV.GetX() > m_animationWrapUV.GetX())
                    {
                        m_animationStateUV.SetX(m_animationStateUV.GetX() - m_animationWrapUV.GetX());
                    }
                    else if(m_animationStateUV.GetX() < -m_animationWrapUV.GetX())
                    {
                        m_animationStateUV.SetX(m_animationStateUV.GetX() + m_animationWrapUV.GetX());
                    }
                    
                    if(m_animationStateUV.GetY() > m_animationWrapUV.GetY())
                    {
                        m_animationStateUV.SetY(m_animationStateUV.GetY() - m_animationWrapUV.GetY());
                    }
                    else if(m_animationStateUV.GetY() < -m_animationWrapUV.GetY())
                    {
                        m_animationStateUV.SetY(m_animationStateUV.GetY() + m_animationWrapUV.GetY());
                    }
                }
                
                void SetState(Rendering::GLState& glState) const
                {
                    m_shader.Use(glState);
                    
                    glState.Blend.Disable();
                    glState.DepthTest.Enable();
                    
                    const Eegeo::m44 &lightColors = m_lighting.GetColors(m_useAlternativeAmbient);
                    m_shader.SetLightColors(lightColors);
                    m_shader.SetLerpParam(m_lerpParam);
                    
                    Lighting::GlobalFoggingUniformValues fogValues;
                    m_fogging.GetUniformValues(fogValues);
                    m_shader.SetFogUniforms(fogValues);
                    m_shader.SetAnimatedUV(m_animationStateUV);
                    m_shader.SetAltitudeEnvMapFade(m_altitudeScale);
                    m_shader.SetWaveDisplacement(1.f); // TODO; drive from theming..
                    
                    Helpers::GLHelpers::BindTexture2D(glState, m_shader.GetFromDiffuseSamplerId(), m_fromDiffuseTextureId, m_textureMinifyType, m_textureRepeat);
                    Helpers::GLHelpers::BindTexture2D(glState, m_shader.GetToDiffuseSamplerId(), m_toDiffuseTextureId, m_textureMinifyType, m_textureRepeat);
                    Helpers::GLHelpers::BindTexture2D(glState, m_shader.GetNormalSamplerId(), m_normalMapTextureId, m_textureMinifyType, m_textureRepeat);
                    Helpers::GLHelpers::BindTexture2D(glState, m_shader.GetFromReflectionSamplerId(), m_fromReflectionMapTextureId, m_textureMinifyType, m_textureRepeat);
                    Helpers::GLHelpers::BindTexture2D(glState, m_shader.GetToReflectionSamplerId(), m_toReflectionMapTextureId, m_textureMinifyType, m_textureRepeat);
                }
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const
                {
                    Rendering::Renderables::WaterRenderable* waterRenderable = (Rendering::Renderables::WaterRenderable*)(renderableBase);
                    m_shader.SetMVP(waterRenderable->GetModelViewProjection());
                    m_shader.SetMV(waterRenderable->GetModelView());
                    m_shader.SetUVBounds(waterRenderable->GetUVBoundsMin(), waterRenderable->GetUVBoundsMax());
                    m_shader.SetPositionBounds(waterRenderable->GetPositionBoundsMin(), waterRenderable->GetPositionBoundsMax());
                    m_shader.SetCameraRelativeOrigin(waterRenderable->GetCameraRelativeModelOrigin());
                }
                
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::WaterTransitionShader& m_shader;
                const Lighting::GlobalLighting& m_lighting;
                const Lighting::GlobalFogging& m_fogging;
                TTextureId m_fromDiffuseTextureId;
                TTextureId m_toDiffuseTextureId;
                TTextureId m_normalMapTextureId;
                TTextureId m_fromReflectionMapTextureId;
                TTextureId m_toReflectionMapTextureId;
                Rendering::TextureMinifyType m_textureMinifyType;
                bool m_textureRepeat;
                bool m_useAlternativeAmbient;
                float m_altitudeScale;
                Eegeo::v2 m_animationScaleUV;
                Eegeo::v2 m_animationWrapUV;
                Eegeo::v4 m_animationStateUV;
                float m_lerpParam;
            };
        }
    }
}
