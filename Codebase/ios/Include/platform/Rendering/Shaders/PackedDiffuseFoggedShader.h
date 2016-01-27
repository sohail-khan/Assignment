// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Shader.h"
#include "GLState.h"
#include "GLHelpers.h"
#include "AllVertexTypes.h"
#include "ShaderMacros.h"
#include "VertexBinding.h"
#include "GlobalFogging.h"
#include "FogShaderUniforms.h"
#include "FogShaderIncludes.h"
#include "FogShaderOld.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace PackedDiffuseFoggedShaderCode
            {
                const std::string PositionName = "Position";
                const std::string UVName = "UV";
                const std::string UnpackModelViewProjectionMatrixName = "UnpackModelViewProjectionMatrix";
                const std::string LightColorMatrixName = "LightColorMatrix";
                const std::string MinUVRangeName = "MinUVRange";
                const std::string MaxUVRangeName = "MaxUVRange";
                const std::string MinPosRangeName = "MinPosRange";
                const std::string MaxPosRangeName = "MaxPosRange";
                const std::string DiffuseName = "Diffuse";
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
                "uniform lowp vec4 "+Rendering::FogShaderIncludes::FogColourName+";\n"
                "uniform sampler2D "+DiffuseName+";\n";
                
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
                "highp vec4 col = " TEXTURE2D(Diffuse, DestinationUV) "; \n"
                "if(col.w<" EEGEO_ALPHA_TEST_VALUE ") discard; \n"
                "gl_FragColor.rgb = mix(col.rgb * ColorVarying.rgb, FogColour.rgb, ColorVarying.a); \n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "gl_FragColor.rgb = mix(" TEXTURE2D(Diffuse, DestinationUV) ".rgb * ColorVarying.rgb, FogColour.rgb, ColorVarying.a); \n"
                "}";

            }
            
            class PackedDiffuseFoggedShader : public Shader
            {
            public:
                static PackedDiffuseFoggedShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(PackedDiffuseFoggedShader)(
                                                                shaderId,
                                                                PackedDiffuseFoggedShaderCode::_vertexDecls + PackedDiffuseFoggedShaderCode::_vertexCode,
                                                                PackedDiffuseFoggedShaderCode::_fragmentDecls + PackedDiffuseFoggedShaderCode::_fragmentCode
                                                                );
                }
                
                static PackedDiffuseFoggedShader* CreateWithPunchThrough(const TShaderId shaderId)
                {
                    return Eegeo_NEW(PackedDiffuseFoggedShader)(
                                                                shaderId,
                                                                PackedDiffuseFoggedShaderCode::_vertexDecls + PackedDiffuseFoggedShaderCode::_vertexCode,
                                                                PackedDiffuseFoggedShaderCode::_fragmentDecls + PackedDiffuseFoggedShaderCode::_fragmentPunchThroughCode
                                                                );
                }
                
                const GLuint GetDiffuseSamplerId() const { return 0; }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }
                
                struct GlobalFoggingUniformValues
                {
                    Eegeo::v4 FogColour;
                    Eegeo::v3 WorldUp;
                    float FogDensityGlobal;
                    float HeightFogIntensity;
                    float DistanceFogIntensity;
                    float CameraAltitude;
                    float HeightFogMinAltitude;
                    float HeightFogMaxAltitude;
                    float DistanceFogNear;
                    float DistanceFogFar;
                    float DistanceFogLow;
                    float DistanceFogHigh;
                };
                
                void SetFogUniforms(Lighting::GlobalFoggingUniformValues& fogUniformValues) const
                {
                    Eegeo::Base::FogShaderOld::SetPerMaterialRenderState(m_fogShaderUniforms, fogUniformValues);
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
                    SetUniformTextureSampler(glState, GetDiffuseSamplerId(), m_diffuseTextureSamplerUniformLocation);
                    
                    const GLfloat lightDotUnpack[] = {1.f, 32.f, 1024.f};
                    SetUniformV3(lightDotUnpack, m_lightDotUnpackUniformLocation);
                }
                
            protected:
                PackedDiffuseFoggedShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_mvpUniformLocation = GetUniformLocation(PackedDiffuseFoggedShaderCode::UnpackModelViewProjectionMatrixName);
                    m_lightColorsUniformLocation = GetUniformLocation(PackedDiffuseFoggedShaderCode::LightColorMatrixName);
                    m_minUVRangeUniformLocation = GetUniformLocation(PackedDiffuseFoggedShaderCode::MinUVRangeName);
                    m_maxUVRangeUniformLocation = GetUniformLocation(PackedDiffuseFoggedShaderCode::MaxUVRangeName);
                    m_minPosRangeUniformLocation = GetUniformLocation(PackedDiffuseFoggedShaderCode::MinPosRangeName);
                    m_maxPosRangeUniformLocation = GetUniformLocation(PackedDiffuseFoggedShaderCode::MaxPosRangeName);
                    m_diffuseTextureSamplerUniformLocation = GetUniformLocation(PackedDiffuseFoggedShaderCode::DiffuseName);
                    m_lightDotUnpackUniformLocation = GetUniformLocation(PackedDiffuseFoggedShaderCode::LightDotUnpackName);
                    m_cameraRelativeModelOriginUniformLocation = GetUniformLocation(Eegeo::Rendering::FogShaderIncludes::CameraRelativeModelOriginName);
                    
                    m_fogShaderUniforms.DetermineUniformsFromShader(this);
                }
                
            private:
                GLuint m_mvpUniformLocation ;
                GLuint m_lightColorsUniformLocation;
                GLuint m_minUVRangeUniformLocation;
                GLuint m_maxUVRangeUniformLocation;
                GLuint m_minPosRangeUniformLocation;
                GLuint m_maxPosRangeUniformLocation;
                GLuint m_diffuseTextureSamplerUniformLocation;
                GLuint m_lightDotUnpackUniformLocation;
                GLuint m_cameraRelativeModelOriginUniformLocation;
                
                Rendering::Shaders::FogShaderUniforms m_fogShaderUniforms;
            };
        }
    }
}
