// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "ShaderMacros.h"
#include "Rendering.h"
#include "VectorMath.h"
#include "Graphics.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace PackedDiffuseShaderCode
            {
                const std::string PositionName = "Position";
                const std::string UVName = "UV";
                const std::string UnpackModelViewProjectionMatrixName = "UnpackModelViewProjectionMatrix";
                const std::string LightColorMatrixName = "LightColorMatrix";
                const std::string MinUVRangeName = "MinUVRange";
                const std::string MaxUVRangeName = "MaxUVRange";
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
                "uniform highp vec3 "+LightDotUnpackName+";\n";
                
                const std::string _fragmentDecls =
                "varying lowp vec4 ColorVarying;\n"
                "varying mediump vec2 DestinationUV;\n"
                "uniform sampler2D "+DiffuseName+";\n";
                
                const std::string _vertexCode =
                "void main(void) { \n"
                "DestinationUV = mix(MinUVRange, MaxUVRange, UV);\n"
                "ColorVarying = LightColorMatrix * vec4(fract(Position.w * LightDotUnpack), 1.0);\n"
                "gl_Position = UnpackModelViewProjectionMatrix * vec4(Position.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentPunchThroughCode =
                "void main(void) { \n"
                "highp vec4 col = " TEXTURE2D(Diffuse, DestinationUV) "; \n"
                "if(col.w<" EEGEO_ALPHA_TEST_VALUE ") discard; \n"
                "gl_FragColor.rgb = col.rgb * ColorVarying.rgb; \n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "gl_FragColor.rgb = " TEXTURE2D(Diffuse, DestinationUV) ".rgb * ColorVarying.rgb; \n"
                "}";
            }
            
            class PackedDiffuseShader : public Shader
            {
            public:
                static PackedDiffuseShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(PackedDiffuseShader)(
                                                        shaderId,
                                                        PackedDiffuseShaderCode::_vertexDecls + PackedDiffuseShaderCode::_vertexCode,
                                                        PackedDiffuseShaderCode::_fragmentDecls + PackedDiffuseShaderCode::_fragmentCode
                                                        );
                }
                
                static PackedDiffuseShader* CreateWithPunchThrough(const TShaderId shaderId)
                {
                    return Eegeo_NEW(PackedDiffuseShader)(
                                                        shaderId,
                                                        PackedDiffuseShaderCode::_vertexDecls + PackedDiffuseShaderCode::_vertexCode,
                                                        PackedDiffuseShaderCode::_fragmentDecls + PackedDiffuseShaderCode::_fragmentPunchThroughCode
                                                        );
                }
                
                const GLuint GetDiffuseSamplerId() const { return 0; }
                    
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
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                    SetUniformTextureSampler(glState, GetDiffuseSamplerId(), m_diffuseTextureSamplerUniformLocation);

                    Eegeo::v3 lightDotUnpack(1.f, 32.f, 1024.f);
                    SetUniformV3(lightDotUnpack, m_lightDotUnpackUniformLocation);
                }

            protected:
                PackedDiffuseShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_mvpUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::UnpackModelViewProjectionMatrixName);
                    m_lightColorsUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::LightColorMatrixName);
                    m_minUVRangeUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::MinUVRangeName);
                    m_maxUVRangeUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::MaxUVRangeName);
                    m_diffuseTextureSamplerUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::DiffuseName);
                    m_lightDotUnpackUniformLocation = GetUniformLocation(PackedDiffuseShaderCode::LightDotUnpackName);
                }
                
            private:
                GLuint m_mvpUniformLocation ;
                GLuint m_lightColorsUniformLocation;
                GLuint m_minUVRangeUniformLocation;
                GLuint m_maxUVRangeUniformLocation;
                GLuint m_diffuseTextureSamplerUniformLocation;
                GLuint m_lightDotUnpackUniformLocation;
            };
        }
    }
}
