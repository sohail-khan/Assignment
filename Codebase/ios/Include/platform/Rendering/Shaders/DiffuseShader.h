// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "Graphics.h"
#include "VectorMath.h"
#include "ShaderMacros.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace DiffuseShaderCode
            {
                const std::string PositionName = "Position";
                const std::string UVName = "UV";
                const std::string ModelViewProjectionMatrixName = "ModelViewProjectionMatrix";
                const std::string LightColorMatrixName = "LightColorMatrix";
                const std::string DiffuseName = "Diffuse";
                const std::string LightDotUnpackName = "LightDotUnpack";
                
                const std::string _vertexDecls =
                "attribute highp vec4 "+PositionName+";\n"
                "attribute lowp vec2 "+UVName+";\n"
                "varying lowp vec4 ColorVarying;\n"
                "varying mediump vec2 DestinationUV;\n"
                "uniform highp mat4 "+ModelViewProjectionMatrixName+";\n"
                "uniform lowp mat4 "+LightColorMatrixName+";\n"
                "uniform highp vec3 "+LightDotUnpackName+";\n";
                
                const std::string _fragmentDecls =
                "varying lowp vec4 ColorVarying;\n"
                "varying mediump vec2 DestinationUV;\n"
                "uniform sampler2D "+DiffuseName+";\n";
                
                const std::string _vertexCode =
                "void main(void) { \n"
                "DestinationUV = UV;\n"
                "ColorVarying = LightColorMatrix * vec4(fract(Position.w * LightDotUnpack), 1.0);\n"
                "gl_Position = ModelViewProjectionMatrix * vec4(Position.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "gl_FragColor.rgb = " TEXTURE2D(Diffuse, DestinationUV) ".rgb * ColorVarying.rgb; \n"
                "}";
            }
            
            class DiffuseShader : public Shader
            {
            public:
                static DiffuseShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(DiffuseShader)(
                                                          shaderId,
                                                          DiffuseShaderCode::_vertexDecls + DiffuseShaderCode::_vertexCode,
                                                          DiffuseShaderCode::_fragmentDecls + DiffuseShaderCode::_fragmentCode
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
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                    SetUniformTextureSampler(glState, GetDiffuseSamplerId(), m_diffuseTextureSamplerUniformLocation);
                    
                    const GLfloat lightDotUnpack[] = {1.f, 32.f, 1024.f};
                    SetUniformV3(lightDotUnpack, m_lightDotUnpackUniformLocation);
                }
                
            protected:
                DiffuseShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    
                    m_mvpUniformLocation = GetUniformLocation(DiffuseShaderCode::ModelViewProjectionMatrixName);
                    m_lightColorsUniformLocation = GetUniformLocation(DiffuseShaderCode::LightColorMatrixName);
                    m_diffuseTextureSamplerUniformLocation = GetUniformLocation(DiffuseShaderCode::DiffuseName);
                    m_lightDotUnpackUniformLocation = GetUniformLocation(DiffuseShaderCode::LightDotUnpackName);
                }
                
            private:
                GLuint m_mvpUniformLocation ;
                GLuint m_lightColorsUniformLocation;
                GLuint m_diffuseTextureSamplerUniformLocation;
                GLuint m_lightDotUnpackUniformLocation;
            };
        }
    }
}