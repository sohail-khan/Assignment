// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "Graphics.h"
#include "Rendering.h"
#include "IdTypes.h"
#include "FogShaderUniforms.h"
#include "FogShaderOld.h"
#include "VectorMath.h"
#include "WaterShader.h"
#include "FogShaderIncludes.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace WaterTransitionShaderCode
            {
                const std::string _fragmentShaderUniformDeclarations =
                "varying highp vec4 ColorVarying;\n"
                "varying highp vec2 DestinationUV;\n"
                "varying highp vec2	DestinationUV2;\n"
                "varying highp vec4 ReflectVector;\n"
                "uniform sampler2D FromDiffuse;\n"
                "uniform sampler2D ToDiffuse;\n"
                "uniform sampler2D NormalMap;\n"
                "uniform sampler2D FromReflectionMap;\n"
                "uniform sampler2D ToReflectionMap;\n"
                "uniform lowp float ReflectionWaveDisplacement;\n"
                "uniform lowp float LerpParam;\n";

                
                const std::string _fragmentShaderMain =
                "void main(void) { \n"
                "highp vec4 diffuseColor = mix(texture2D(FromDiffuse, DestinationUV), texture2D(ToDiffuse, DestinationUV), LerpParam);\n"
                "highp vec3 normal = ((2.0 * texture2D(NormalMap, DestinationUV2).xyz) - 1.0);\n"
                "highp vec3 refl = normalize(ReflectVector.xyz + normal*ReflectionWaveDisplacement);\n"
                "highp vec2 uv = ((refl.xy * 0.5) + 0.5);\n"
                "highp vec4 reflection = mix(texture2D(FromReflectionMap, uv), texture2D(ToReflectionMap, uv), LerpParam);\n"
                "lowp vec3 colour = (diffuseColor.xyz * ColorVarying.xyz) + (reflection.xyz * ColorVarying.w);\n"
                "gl_FragColor.rgb = mix(colour, FogColour.rgb, ReflectVector.w);\n"
                "}\n";
                
            }
            
            class WaterTransitionShader : public Shader
            {
            public:
                static WaterTransitionShader* Create(const TShaderId shaderId)
                {
                    std::string vertexShaderCode = WaterShaderCode::_vertexShaderUniformDeclarations + FOG_VERTEX_SHADER_UNIFORMS + FOG_VERTEX_SHADER_FUNCTIONS + WaterShaderCode::_vertexShaderMain;
                    std::string fragmentShaderCode = WaterTransitionShaderCode::_fragmentShaderUniformDeclarations + FOG_FRAGMENT_SHADER_UNIFORMS + WaterTransitionShaderCode::_fragmentShaderMain;
                    
                    return Eegeo_NEW(WaterTransitionShader)(
                                                  shaderId,
                                                  vertexShaderCode,
                                                  fragmentShaderCode
                                                  );
                }
                
                const GLuint GetFromDiffuseSamplerId() const { return 0; }
                const GLuint GetToDiffuseSamplerId() const { return 1; }
                const GLuint GetNormalSamplerId() const { return 2; }
                const GLuint GetFromReflectionSamplerId() const { return 3; }
                const GLuint GetToReflectionSamplerId() const { return 3; }
                
                void SetLerpParam(const float l)
                {
                    SetUniformFloat(l, m_lerpParamUniform);
                }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_modelViewProjectionUniform, transpose);
                }
                
                void SetMV(const m44& mv) const
                {
                    bool transpose = false;
                    SetUniformM44(mv, m_modelViewUniform, transpose);
                }
                
                void SetFogUniforms(Lighting::GlobalFoggingUniformValues& fogUniformValues) const
                {
                    Eegeo::Base::FogShaderOld::SetPerMaterialRenderState(m_fogShaderUniforms, fogUniformValues);
                }
                
                void SetLightColors(const m44& colors) const
                {
                    bool transpose = false;
                    SetUniformM44(colors, m_lightColorsUniform, transpose);
                }
                
                void SetAnimatedUV(const v4& uv) const
                {
                    SetUniformV4(uv, m_animatedUVUniform);
                }
                
                void SetAltitudeEnvMapFade(const float v) const
                {
                    SetUniformFloat(v, m_altitudeEnvMapFadeUniform);
                }
                
                void SetUVBounds(const Eegeo::v2& min, const Eegeo::v2& max) const
                {
                    SetUniformV2(min, m_minUVRangeUniform);
                    SetUniformV2(max, m_maxUVRangeUniform);
                }
                
                void SetPositionBounds(const Eegeo::v4& min, const Eegeo::v4& max) const
                {
                    SetUniformV4(min, m_minVertRangeUniform);
                    SetUniformV4(max, m_maxVertRangeUniform);
                }
                
                void SetWaveDisplacement(const float v) const
                {
                    SetUniformFloat(v, m_reflectionWaveDisplacementUniform);
                }
                
                void SetCameraRelativeOrigin(const Eegeo::v3& cameraRelativeOrigin) const
                {
                    SetUniformV3(cameraRelativeOrigin, m_cameraRelativeModelOriginUniformLocation);
                }
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                    SetUniformTextureSampler(glState, GetFromDiffuseSamplerId(), m_fromDiffuseTextureSampler);
                    SetUniformTextureSampler(glState, GetToDiffuseSamplerId(), m_toDiffuseTextureSampler);
                    SetUniformTextureSampler(glState, GetNormalSamplerId(), m_normalMapTextureSampler);
                    SetUniformTextureSampler(glState, GetFromReflectionSamplerId(), m_fromReflectionMapTextureSampler);
                    SetUniformTextureSampler(glState, GetToReflectionSamplerId(), m_toReflectionMapTextureSampler);
                }
                
            protected:
                WaterTransitionShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_modelViewProjectionUniform = GetUniformLocation("ModelViewProjectionMatrix");
                    m_modelViewUniform = GetUniformLocation("ModelViewMatrix");
                    m_lightColorsUniform = GetUniformLocation("LightColorMatrix");
                    m_animatedUVUniform = GetUniformLocation("AnimatedUVUniform");
                    m_fromDiffuseTextureSampler = GetUniformLocation("FromDiffuse");
                    m_toDiffuseTextureSampler = GetUniformLocation("ToDiffuse");
                    m_normalMapTextureSampler = GetUniformLocation("NormalMap");
                    m_fromReflectionMapTextureSampler = GetUniformLocation("FromReflectionMap");
                    m_toReflectionMapTextureSampler = GetUniformLocation("ToReflectionMap");
                    m_altitudeEnvMapFadeUniform = GetUniformLocation("AltitudeEnvMapFade");
                    m_lerpParamUniform = GetUniformLocation("LerpParam");
                    
                    m_minVertRangeUniform = GetUniformLocation("MinVertRange");
                    m_maxVertRangeUniform = GetUniformLocation("MaxVertRange");
                    m_minUVRangeUniform = GetUniformLocation("MinUVRange");
                    m_maxUVRangeUniform = GetUniformLocation("MaxUVRange");
                    m_reflectionWaveDisplacementUniform = GetUniformLocation("ReflectionWaveDisplacement");
                    
                    m_cameraRelativeModelOriginUniformLocation = GetUniformLocation("CameraRelativeModelOrigin");
                    
                    m_fogShaderUniforms.DetermineUniformsFromShader(this);
                }
                
            private:
                GLuint m_modelViewProjectionUniform;
                GLuint m_modelViewUniform;
                GLuint m_altitudeEnvMapFadeUniform;
                GLuint m_lightColorsUniform;
                GLuint m_minVertRangeUniform;
                GLuint m_maxVertRangeUniform;
                GLuint m_minUVRangeUniform;
                GLuint m_maxUVRangeUniform;
                GLuint m_fromDiffuseTextureSampler;
                GLuint m_toDiffuseTextureSampler;
                GLuint m_normalMapTextureSampler;
                GLuint m_fromReflectionMapTextureSampler;
                GLuint m_toReflectionMapTextureSampler;
                GLuint m_animatedUVUniform;
                GLuint m_reflectionWaveDisplacementUniform;
                GLuint m_cameraRelativeModelOriginUniformLocation;
                GLuint m_lerpParamUniform;
                Rendering::Shaders::FogShaderUniforms m_fogShaderUniforms;
            };
        }
    }
}