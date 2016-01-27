// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "ShaderMacros.h"
#include "IdTypes.h"
#include "Graphics.h"
#include "Rendering.h"
#include "VectorMath.h"
#include "FogShaderOld.h"
#include "FogShaderUniforms.h"
#include "FogShaderIncludes.h"
#include "GlobalFogging.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace PackedDiffuseTransitionShaderCode
            {
                const std::string PositionName = "Position";
                const std::string UVName = "UV";
                const std::string UnpackModelViewProjectionMatrixName = "UnpackModelViewProjectionMatrix";
                const std::string LightColorMatrixName = "LightColorMatrix";
                const std::string MinUVRangeName = "MinUVRange";
                const std::string MaxUVRangeName = "MaxUVRange";
                const std::string MinPosRangeName = "MinPosRange";
                const std::string MaxPosRangeName = "MaxPosRange";
                const std::string DiffuseFromName = "DiffuseFrom";
                const std::string DiffuseToName = "DiffuseTo";
                const std::string LerpParamName = "LerpParam";
                const std::string LightDotUnpackName = "LightDotUnpack";
                
                const std::string _vertexDecls =
                "attribute mediump vec4 "+PositionName+";\n"
                "attribute lowp vec2 "+UVName+";\n"
                "varying lowp vec4 ColorVarying;\n"
                "varying mediump vec2 DestinationUV;\n"
                "uniform highp mat4 "+UnpackModelViewProjectionMatrixName+";\n"
                "uniform lowp mat4 "+LightColorMatrixName+";\n"
                "uniform highp vec2 "+MinUVRangeName+";\n"
                "uniform highp vec2 "+MaxUVRangeName+";\n"
                "uniform highp vec4 "+MinPosRangeName+";\n"
                "uniform highp vec4 "+MaxPosRangeName+";\n"
                "uniform highp vec3 "+LightDotUnpackName+";\n"
                FOG_VERTEX_SHADER_UNIFORMS;
                
                const std::string _fragmentDecls =
                "varying lowp vec4 ColorVarying;\n"
                "varying mediump vec2 DestinationUV;\n"
                "uniform sampler2D "+DiffuseFromName+";\n"
                "uniform sampler2D "+DiffuseToName+";\n"
                "uniform lowp vec4 "+Rendering::FogShaderIncludes::FogColourName+";\n"
                "uniform lowp float "+LerpParamName+";\n";
                
                const std::string _vertexCode =
                FOG_VERTEX_SHADER_FUNCTIONS
                "void main(void) { \n"
                "DestinationUV = mix(MinUVRange, MaxUVRange, UV);\n"
                "mediump vec3 unpackedPosition = mix(MinPosRange.xyz, MaxPosRange.xyz, Position.xyz);\n"
                "ColorVarying.rgb = (LightColorMatrix * vec4(fract(Position.w * LightDotUnpack), 1.0)).rgb;\n"
                "ColorVarying.a = CalcHeightFogDensity(unpackedPosition);\n"
                "gl_Position = UnpackModelViewProjectionMatrix * vec4(Position.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentPunchThroughCode =
                "void main(void) { \n"
                "highp vec4 fromColor = " TEXTURE2D(DiffuseFrom, DestinationUV) "; \n"
                "highp vec4 toColor = " TEXTURE2D(DiffuseTo, DestinationUV) "; \n"
                "highp vec4 col = mix(fromColor, toColor, LerpParam);\n"
                "if(col.w<" EEGEO_ALPHA_TEST_VALUE ") discard; \n"
                "gl_FragColor.rgb = mix(col.rgb * ColorVarying.rgb, FogColour.rgb, ColorVarying.a); \n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "highp vec3 fromColor = " TEXTURE2D(DiffuseFrom, DestinationUV) ".rgb; \n"
                "highp vec3 toColor = " TEXTURE2D(DiffuseTo, DestinationUV) ".rgb; \n"
                "gl_FragColor.rgb = mix(mix(fromColor, toColor, LerpParam) * ColorVarying.rgb, FogColour.rgb, ColorVarying.a);\n"
                "}";
            }
            
            class PackedDiffuseTransitionShader : public Shader
            {
            public:
                static PackedDiffuseTransitionShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(PackedDiffuseTransitionShader)(
                                                                    shaderId,
                                                                    PackedDiffuseTransitionShaderCode::_vertexDecls + PackedDiffuseTransitionShaderCode::_vertexCode,
                                                                    PackedDiffuseTransitionShaderCode::_fragmentDecls + PackedDiffuseTransitionShaderCode::_fragmentCode
                                                                    );
                }
                
                static PackedDiffuseTransitionShader* CreateWithPunchThrough(const TShaderId shaderId)
                {
                    return Eegeo_NEW(PackedDiffuseTransitionShader)(
                                                                    shaderId,
                                                                    PackedDiffuseTransitionShaderCode::_vertexDecls + PackedDiffuseTransitionShaderCode::_vertexCode,
                                                                    PackedDiffuseTransitionShaderCode::_fragmentDecls + PackedDiffuseTransitionShaderCode::_fragmentPunchThroughCode
                                                                    );
                }
                
                const GLuint GetFromDiffuseSamplerId() const { return 0; }
                const GLuint GetToDiffuseSamplerId() const { return 1; }
                
                void SetFogUniforms(Lighting::GlobalFoggingUniformValues& fogUniformValues) const
                {
                    Eegeo::Base::FogShaderOld::SetPerMaterialRenderState(m_fogShaderUniforms, fogUniformValues);
                }

                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }
                
                void SetLightColors(const m44& colors) const
                {
                    bool transpose = false;
                    SetUniformM44(colors, m_lightColorsUniformLocation, transpose);
                }
                
                void SetUVBounds(const Eegeo::v2& min, const Eegeo::v2& max) const
                {
                    SetUniformV2(min, m_minUVRangeUniformLocation);
                    SetUniformV2(max, m_maxUVRangeUniformLocation);
                }
                
                void SetLerpParam(float t) const
                {
                    SetUniformFloat(t, m_lerpParamUniformLocation);
                }
                
                void SetPositionBounds(const Eegeo::v4& min, const Eegeo::v4& max) const
                {
                    SetUniformV4(min, m_minPosRangeUniformLocation);
                    SetUniformV4(max, m_maxPosRangeUniformLocation);
                }
                
                void SetCameraRelativeOrigin(const Eegeo::v3& cameraRelativeOrigin) const
                {
                    SetUniformV3(cameraRelativeOrigin, m_cameraRelativeModelOriginUniformLocation);
                }
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                    SetUniformTextureSampler(glState, GetFromDiffuseSamplerId(), m_fromDiffuseTextureSamplerUniformLocation);
                    SetUniformTextureSampler(glState, GetToDiffuseSamplerId(), m_toDiffuseTextureSamplerUniformLocation);
                    
                    const GLfloat lightDotUnpack[] = {1.f, 32.f, 1024.f};
                    SetUniformV3(lightDotUnpack, m_lightDotUnpackUniformLocation);
                }
                
            protected:
                PackedDiffuseTransitionShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_mvpUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::UnpackModelViewProjectionMatrixName);
                    m_lightColorsUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::LightColorMatrixName);
                    m_minUVRangeUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::MinUVRangeName);
                    m_maxUVRangeUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::MaxUVRangeName);
                    m_minPosRangeUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::MinPosRangeName);
                    m_maxPosRangeUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::MaxPosRangeName);

                    m_fromDiffuseTextureSamplerUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::DiffuseFromName);
                    m_toDiffuseTextureSamplerUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::DiffuseToName);
                    m_lerpParamUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::LerpParamName);
                    m_lightDotUnpackUniformLocation = GetUniformLocation(PackedDiffuseTransitionShaderCode::LightDotUnpackName);
                    m_cameraRelativeModelOriginUniformLocation = GetUniformLocation(Eegeo::Rendering::FogShaderIncludes::CameraRelativeModelOriginName);
                    
                    m_fogShaderUniforms.DetermineUniformsFromShader(this);
                }
                
            protected:
                GLuint m_mvpUniformLocation ;
                GLuint m_lightColorsUniformLocation;
                GLuint m_minUVRangeUniformLocation;
                GLuint m_maxUVRangeUniformLocation;
                GLuint m_minPosRangeUniformLocation;
                GLuint m_maxPosRangeUniformLocation;
                GLuint m_toDiffuseTextureSamplerUniformLocation;
                GLuint m_fromDiffuseTextureSamplerUniformLocation;
                GLuint m_lerpParamUniformLocation;
                GLuint m_lightDotUnpackUniformLocation;
                GLuint m_cameraRelativeModelOriginUniformLocation;

                Rendering::Shaders::FogShaderUniforms m_fogShaderUniforms;
            };
        }
    }
}

