// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PackedDiffuseShader.h"
#include "ShaderMacros.h"
#include "VectorMath.h"
#include "FogShaderIncludes.h"
#include "FogShaderUniforms.h"
#include "Graphics.h"
#include "FogShaderOld.h"
#include "GlobalFogging.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace LightmappedPackedDiffuseShaderCode
            {
                const std::string UV2Name = "UV2";
                const std::string GlowmapName = "Glowmap";
                const std::string GlowmapColourName = "GlowmapColour";
                const std::string GlowmapParamName = "GlowmapParam";
                const std::string AmbientColourName = "AmbientColour";
                const std::string MinPosRangeName = "MinPosRange";
                const std::string MaxPosRangeName = "MaxPosRange";

                const std::string _vertexDecls =
                "attribute lowp vec2 "+UV2Name+";\n"
                "varying highp vec2 DestinationUV2;\n"
                "uniform highp vec4 "+MinPosRangeName+";\n"
                "uniform highp vec4 "+MaxPosRangeName+";\n"
                FOG_VERTEX_SHADER_UNIFORMS;
                
                const std::string _fragmentDecls =
                "varying highp vec2 DestinationUV2;\n"
                "uniform lowp float "+GlowmapParamName+";\n"
                "uniform lowp vec3 "+GlowmapColourName+";\n"
                "uniform lowp vec3 "+AmbientColourName+";\n"
                "uniform lowp vec4 "+Rendering::FogShaderIncludes::FogColourName+";\n"
                "uniform sampler2D "+GlowmapName+";\n";
                
                const std::string _vertexCode =
                FOG_VERTEX_SHADER_FUNCTIONS
                "void main(void) { \n"
                "DestinationUV = mix(MinUVRange, MaxUVRange, UV);\n"
                "DestinationUV2 = UV2;\n"
                "mediump vec3 unpackedPosition = mix(MinPosRange.xyz, MaxPosRange.xyz, Position.xyz);\n"
                "ColorVarying.rgb = (LightColorMatrix * vec4(fract(Position.w * LightDotUnpack), 1.0)).rgb;\n"
                "ColorVarying.a = CalcHeightFogDensity(unpackedPosition);\n"
                "gl_Position = UnpackModelViewProjectionMatrix * vec4(Position.rgb, 1.0);\n"
                "}";
                
                const std::string _fragmentPunchThroughCode =
                "void main(void) { \n"
                "highp vec4 col = " TEXTURE2D(Diffuse, DestinationUV) "; \n"
                "if(col.w<" EEGEO_ALPHA_TEST_VALUE ") discard; \n"
                "gl_FragColor.rgb = col.rgb * ColorVarying.rgb; \n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "lowp vec3 diffuse = " TEXTURE2D(Diffuse, DestinationUV) ".rgb;\n"
                "lowp vec3 dayColour = diffuse * ColorVarying.rgb;\n"
                "lowp float luma = dot(diffuse, vec3(0.3, 0.59, 0.11));\n"
                "lowp vec3 greyscale = vec3(luma, luma, luma);\n"
                "lowp vec3 glow = "+GlowmapColourName+" * " TEXTURE2D(Glowmap, DestinationUV2) ".rgb;\n"
                "lowp vec3 desatDiffuse = mix(greyscale, diffuse, 0.2);\n"
                "lowp vec3 nightColour = desatDiffuse * (glow + "+AmbientColourName+");\n"
                "gl_FragColor.rgb = mix(mix(dayColour, nightColour, "+GlowmapParamName+"), FogColour.rgb, ColorVarying.a); \n"
                "}";
            }
            
            class LightmappedPackedDiffuseShader : public PackedDiffuseShader
            {
            public:
                static LightmappedPackedDiffuseShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(LightmappedPackedDiffuseShader)(
                                                                     shaderId,
                                                                     PackedDiffuseShaderCode::_vertexDecls + LightmappedPackedDiffuseShaderCode::_vertexDecls + LightmappedPackedDiffuseShaderCode::_vertexCode,
                                                                     PackedDiffuseShaderCode::_fragmentDecls + LightmappedPackedDiffuseShaderCode::_fragmentDecls + LightmappedPackedDiffuseShaderCode::_fragmentCode
                                                                     );
                }
                
                const GLuint GetLightmapSamplerId() const { return 1; }
                
                void SetFogUniforms(Lighting::GlobalFoggingUniformValues& fogUniformValues) const
                {
                    Base::FogShaderOld::SetPerMaterialRenderState(m_fogShaderUniforms, fogUniformValues);
                }

                void SetLightmapColour(const v3& color) const
                {
                    SetUniformV3(color, m_glowMapColourUniformLocation);
                }

                void SetLightmapIntensity(const float intensity) const
                {
                    SetUniformFloat(intensity, m_glowMapParamUniformLocation);
                }
                
                void SetAmbientColor(const v3& color) const
                {
                    SetUniformV3(color, m_ambientUniformLocation);
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
                    SetUniformTextureSampler(glState, GetLightmapSamplerId(), m_glowMapTextureSamplerUniformLocation);
                    
                    const GLfloat lightDotUnpack[] = {1.f, 32.f, 1024.f};
                    SetUniformV3(lightDotUnpack, m_lightDotUnpackUniformLocation);
                }
                
            protected:
                LightmappedPackedDiffuseShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode)
                : PackedDiffuseShader(shaderId, vertexShaderCode, fragmentShaderCode)
                {
                    m_glowMapColourUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::GlowmapColourName);
                    m_glowMapParamUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::GlowmapParamName);
                   
                    m_diffuseTextureSamplerUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::DiffuseName);
                    m_glowMapTextureSamplerUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::GlowmapName);
                    
                    m_lightDotUnpackUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::LightDotUnpackName);
                    m_ambientUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::AmbientColourName);
                    
                    m_cameraRelativeModelOriginUniformLocation = GetUniformLocation(Eegeo::Rendering::FogShaderIncludes::CameraRelativeModelOriginName);

                    m_minPosRangeUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::MinPosRangeName);
                    m_maxPosRangeUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::MaxPosRangeName);
                    
                    m_fogShaderUniforms.DetermineUniformsFromShader(this);
                }
                
            private:
                GLuint m_glowMapColourUniformLocation;
                GLuint m_glowMapParamUniformLocation;
                GLuint m_diffuseTextureSamplerUniformLocation;
                GLuint m_glowMapTextureSamplerUniformLocation;
                GLuint m_lightDotUnpackUniformLocation;
                GLuint m_ambientUniformLocation;
                GLuint m_minPosRangeUniformLocation;
                GLuint m_maxPosRangeUniformLocation;
                GLuint m_cameraRelativeModelOriginUniformLocation;
                
                Rendering::Shaders::FogShaderUniforms m_fogShaderUniforms;
            };
        }
    }
}
