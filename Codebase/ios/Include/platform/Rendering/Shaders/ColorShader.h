// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "VectorMath.h"
#include "Graphics.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace ColorShaderCode
            {
                const std::string PositionName = "Position";
                const std::string ModelViewProjectionMatrixName = "ModelViewProjectionMatrix";
                const std::string ColorName = "ColorValue";
                
                const std::string _vertexDecls =
                "attribute mediump vec4 "+PositionName+";\n"
                "uniform highp mat4 "+ModelViewProjectionMatrixName+";\n";
                
                const std::string _fragmentDecls =
                "uniform lowp vec4 "+ColorName+";\n";
                
                const std::string _vertexCode =
                "void main(void) { \n"
                "gl_Position = "+ModelViewProjectionMatrixName+" * vec4(Position.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "gl_FragColor.rgba = "+ColorName+".rgba; \n"
                "}";

            }
            
            class ColorShader : public Shader
            {
            public:
                static ColorShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(ColorShader)(
                                                  shaderId,
                                                  ColorShaderCode::_vertexDecls + ColorShaderCode::_vertexCode,
                                                  ColorShaderCode::_fragmentDecls + ColorShaderCode::_fragmentCode
                                                  );
                }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }
                
                void SetColor(const v4& color) const
                {
                    SetUniformV4(color, m_colorUniformLocation);
                }
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                }
                
            protected:
                ColorShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    m_mvpUniformLocation = GetUniformLocation(ColorShaderCode::ModelViewProjectionMatrixName);
                    m_colorUniformLocation = GetUniformLocation(ColorShaderCode::ColorName);
                }
                
            private:
                GLuint m_mvpUniformLocation;
                GLuint m_colorUniformLocation;
            };
        }
    }
}
