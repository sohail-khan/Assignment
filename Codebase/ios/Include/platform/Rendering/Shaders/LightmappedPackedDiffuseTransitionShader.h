// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PackedDiffuseTransitionShader.h"
#include "ShaderMacros.h"
#include "FogShaderIncludes.h"
#include "VectorMath.h"
#include "Graphics.h"
#include "LightmappedPackedDiffuseShader.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace LightmappedPackedDiffuseTransitionShaderCode
            {
                const std::string UV2Name = "UV2";
                const std::string GlowmapName = "Glowmap";
                const std::string GlowmapColourName = "GlowmapColour";
                const std::string GlowmapParamName = "GlowmapParam";
                const std::string AmbientColourName = "AmbientColour";
                
                const std::string _vertexDecls =
                "attribute lowp vec2 "+UV2Name+";\n"
                "varying highp vec2 DestinationUV2;\n";
                
                const std::string _fragmentDecls =
                "varying highp vec2 DestinationUV2;\n"
                "uniform lowp float "+GlowmapParamName+";\n"
                "uniform lowp vec3 "+GlowmapColourName+";\n"
                "uniform sampler2D "+GlowmapName+";\n"
                "uniform lowp vec3 "+AmbientColourName+";\n";
                
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
                "highp vec3 fromColor = " TEXTURE2D(DiffuseFrom, DestinationUV) ".rgb; \n"
                "highp vec3 toColor = " TEXTURE2D(DiffuseTo, DestinationUV) ".rgb; \n"
                "lowp vec3 diffuse = mix(fromColor, toColor, LerpParam);\n"
                "lowp vec3 dayColour = diffuse * ColorVarying.rgb;\n"
                "lowp float luma = dot(diffuse, vec3(0.3, 0.59, 0.11));\n"
                "lowp vec3 greyscale = vec3(luma, luma, luma);\n"
                "lowp vec3 glow = "+GlowmapColourName+" * " TEXTURE2D(Glowmap, DestinationUV2) ".rgb;\n"
                "lowp vec3 desatDiffuse = mix(greyscale, diffuse, 0.2);\n"
                "lowp vec3 nightColour = desatDiffuse * (glow + "+AmbientColourName+");\n"
                "gl_FragColor.rgb = mix(mix(dayColour, nightColour, "+GlowmapParamName+"), FogColour.rgb, ColorVarying.a); \n"
                "}";
            }
            
            class LightmappedPackedDiffuseTransitionShader : public PackedDiffuseTransitionShader
            {
            public:
                static LightmappedPackedDiffuseTransitionShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(LightmappedPackedDiffuseTransitionShader)(
                                                                     shaderId,
                                                                     PackedDiffuseTransitionShaderCode::_vertexDecls + LightmappedPackedDiffuseTransitionShaderCode::_vertexDecls + LightmappedPackedDiffuseTransitionShaderCode::_vertexCode,
                                                                     PackedDiffuseTransitionShaderCode::_fragmentDecls + LightmappedPackedDiffuseTransitionShaderCode::_fragmentDecls + LightmappedPackedDiffuseTransitionShaderCode::_fragmentCode
                                                                     );
                }
                
                const GLuint GetLightmapSamplerId() const { return 2; }
                
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
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                    
                    SetUniformTextureSampler(glState, GetFromDiffuseSamplerId(), m_fromDiffuseTextureSamplerUniformLocation);
                    SetUniformTextureSampler(glState, GetToDiffuseSamplerId(), m_toDiffuseTextureSamplerUniformLocation);
                    SetUniformTextureSampler(glState, GetLightmapSamplerId(), m_glowMapTextureSamplerUniformLocation);
                    
                    const GLfloat lightDotUnpack[] = {1.f, 32.f, 1024.f};
                    SetUniformV3(lightDotUnpack, m_lightDotUnpackUniformLocation);
                }
                
            protected:
                LightmappedPackedDiffuseTransitionShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode)
                : PackedDiffuseTransitionShader(shaderId, vertexShaderCode, fragmentShaderCode)
                {
                    m_glowMapColourUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::GlowmapColourName);
                    m_glowMapParamUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::GlowmapParamName);
                    
                    m_glowMapTextureSamplerUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::GlowmapName);
                    
                    m_lightDotUnpackUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::LightDotUnpackName);
                    m_ambientUniformLocation = GetUniformLocation(LightmappedPackedDiffuseShaderCode::AmbientColourName);
                }
                
            private:
                GLuint m_glowMapColourUniformLocation;
                GLuint m_glowMapParamUniformLocation;
                GLuint m_glowMapTextureSamplerUniformLocation;
                GLuint m_lightDotUnpackUniformLocation;
                GLuint m_ambientUniformLocation;
            };
        }
    }
}
