// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "Rendering.h"
#include "Graphics.h"
#include "VectorMath.h"
#include "IdTypes.h"
#include "FogShaderUniforms.h"
#include "FogShaderIncludes.h"
#include "FogShaderOld.h"
#include "GlobalFogging.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace WaterShaderCode
            {
                const std::string _vertexShaderUniformDeclarations =
                "attribute highp vec4 Position;\n"
                "attribute highp vec2 UV;\n"
                "varying highp vec2 DestinationUV;\n"
                "varying highp vec4 ColorVarying;\n"
                "varying highp vec2	DestinationUV2;\n"
                "varying highp vec4 ReflectVector;\n"
                "uniform highp mat4 ModelViewProjectionMatrix;\n"
                "uniform highp mat4 ModelViewMatrix;\n"
                "uniform highp mat4 LightColorMatrix;\n"
                "uniform highp vec4 AnimatedUVUniform;\n"
                "uniform highp float AltitudeEnvMapFade;\n"
                "uniform highp vec4 MinVertRange;\n"
                "uniform highp vec4 MaxVertRange;\n"
                "uniform highp vec2 MinUVRange;\n"
                "uniform highp vec2 MaxUVRange;\n";
                
                const std::string _vertexShaderMain =
                "void main(void) { \n"
                "highp vec2 baseUVOffset = AnimatedUVUniform.xy * AnimatedUVUniform.zw;\n"
                "highp vec2 ScaledUV = mix(MinUVRange, MaxUVRange, UV).xy;\n"
                "DestinationUV = baseUVOffset.xy + (ScaledUV.xy);\n"
                "highp vec3 dots = fract(vec3(Position.w * 1.0, Position.w * 32.0, Position.w * 1024.0));\n"
                "ColorVarying = (LightColorMatrix * vec4(dots, 1.0));\n"
                "DestinationUV2 = (ScaledUV * 4.0) + (baseUVOffset * 3.0);\n"
                "highp vec3 truePos = mix(MinVertRange.xyz, MaxVertRange.xyz, Position.xyz);\n"
                "highp vec3 posVS = (ModelViewMatrix * vec4(truePos.xyz, 1.0)).xyz;\n"
                "highp vec3 eyeVectorVS = normalize(posVS);\n"
                "highp vec3 normal = vec3(0,0,1);\n"
                "ReflectVector.xyz = reflect(eyeVectorVS, normal) * 32.0;\n"
                "ReflectVector.w = CalcHeightFogDensity(truePos);\n"
                "ColorVarying = (ColorVarying * (1.0 - AltitudeEnvMapFade)) + (ColorVarying * 0.1);\n"
                "ColorVarying.w = AltitudeEnvMapFade;\n"
                "gl_Position = ModelViewProjectionMatrix * vec4(truePos.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentShaderUniformDeclarations =
                "varying highp vec4 ColorVarying;\n"
                "varying highp vec2 DestinationUV;\n"
                "varying highp vec2	DestinationUV2;\n"
                "varying highp vec4 ReflectVector;\n"
                "uniform sampler2D Diffuse;\n"
                "uniform sampler2D NormalMap;\n"
                "uniform sampler2D ReflectionMap;\n"
                "uniform lowp float ReflectionWaveDisplacement;\n";
                
                const std::string _fragmentShaderMain =
                "void main(void) { \n"
                "highp vec4 diffuseColor = texture2D(Diffuse, DestinationUV);\n"
                "highp vec3 normal = ((2.0 * texture2D(NormalMap, DestinationUV2).xyz) - 1.0);\n"
                "highp vec3 refl = normalize(ReflectVector.xyz + normal*ReflectionWaveDisplacement);\n"
                "highp vec2 uv = ((refl.xy * 0.5) + 0.5);\n"
                "highp vec4 reflection = texture2D(ReflectionMap, uv);\n"
                "lowp vec3 colour = (diffuseColor.xyz * ColorVarying.xyz) + (reflection.xyz * ColorVarying.w);\n"
                "gl_FragColor.rgb = mix(colour, FogColour.rgb, ReflectVector.w);\n"
                "}\n";

            }
            
            class WaterShader : public Eegeo::Rendering::Shader
            {
            public:
                static WaterShader* Create(const TShaderId shaderId)
                {
                    std::string vertexShaderCode = WaterShaderCode::_vertexShaderUniformDeclarations + FOG_VERTEX_SHADER_UNIFORMS + FOG_VERTEX_SHADER_FUNCTIONS + WaterShaderCode::_vertexShaderMain;
                    std::string fragmentShaderCode = WaterShaderCode::_fragmentShaderUniformDeclarations + FOG_FRAGMENT_SHADER_UNIFORMS + WaterShaderCode::_fragmentShaderMain;

                    return Eegeo_NEW(WaterShader)(
                                                      shaderId,
                                                      vertexShaderCode,
                                                      fragmentShaderCode
                                                  );
                }
                
                const GLuint GetDiffuseSamplerId() const { return 0; }
                const GLuint GetNormalSamplerId() const { return 1; }
                const GLuint GetReflectionSamplerId() const { return 2; }
                
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
                    SetUniformTextureSampler(glState, GetDiffuseSamplerId(), m_diffuseTextureSampler);
                    SetUniformTextureSampler(glState, GetNormalSamplerId(), m_normalMapTextureSampler);
                    SetUniformTextureSampler(glState, GetReflectionSamplerId(), m_reflectionMapTextureSampler);
                }
                
            protected:
                WaterShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);

                    m_modelViewProjectionUniform = GetUniformLocation("ModelViewProjectionMatrix");
                    m_modelViewUniform = GetUniformLocation("ModelViewMatrix");
                    m_lightColorsUniform = GetUniformLocation("LightColorMatrix");
                    m_animatedUVUniform = GetUniformLocation("AnimatedUVUniform");
                    m_diffuseTextureSampler = GetUniformLocation("Diffuse");
                    m_normalMapTextureSampler = GetUniformLocation("NormalMap");
                    m_reflectionMapTextureSampler = GetUniformLocation("ReflectionMap");
                    m_altitudeEnvMapFadeUniform = GetUniformLocation("AltitudeEnvMapFade");
                    
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
                GLuint m_diffuseTextureSampler;
                GLuint m_normalMapTextureSampler;
                GLuint m_reflectionMapTextureSampler;
                GLuint m_animatedUVUniform;
                GLuint m_reflectionWaveDisplacementUniform;
                GLuint m_cameraRelativeModelOriginUniformLocation;
                Rendering::Shaders::FogShaderUniforms m_fogShaderUniforms;
            };
        }
    }
}
