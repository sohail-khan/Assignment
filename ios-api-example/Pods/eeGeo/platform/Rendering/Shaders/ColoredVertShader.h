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
            namespace ColoredVertShaderCode
            {
                const std::string PositionName = "Position";
                const std::string ModelViewProjectionMatrixName = "ModelViewProjectionMatrix";
                const std::string ColorName = "Color";
                const std::string ColorVaryingName = "ColorVarying";
                
                const std::string _vertexDecls =
                "attribute mediump vec4 "+PositionName+";\n"
                "attribute vec4 "+ColorName+";\n"
                "varying lowp vec4 "+ColorVaryingName+";\n"
                "uniform highp mat4 "+ModelViewProjectionMatrixName+";\n";
                
                const std::string _fragmentDecls =
                "varying lowp vec4 "+ColorVaryingName+";\n";
                
                const std::string _vertexCode =
                "void main(void) { \n"
                ""+ColorVaryingName+" = "+ColorName+";\n"
                "gl_Position = "+ModelViewProjectionMatrixName+" * vec4(Position.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "gl_FragColor.rgba = "+ColorVaryingName+".rgba; \n"
                "}";
                
            }
            
            class ColoredVertShader : public Shader
            {
            public:
                static ColoredVertShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(ColoredVertShader)(
                                                        shaderId,
                                                        ColoredVertShaderCode::_vertexDecls + ColoredVertShaderCode::_vertexCode,
                                                        ColoredVertShaderCode::_fragmentDecls + ColoredVertShaderCode::_fragmentCode
                                                        );
                }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }
                
                GLuint GetPositionUniform() const { return GetVertexAttributes().GetElement(0).GetLocation(); }
                GLuint GetColorUniform() const { return GetVertexAttributes().GetElement(1).GetLocation(); }
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                }
                
            protected:
                ColoredVertShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    m_mvpUniformLocation = GetUniformLocation(ColoredVertShaderCode::ModelViewProjectionMatrixName);
                }
                
                
                
            private:
                GLuint m_mvpUniformLocation;
            };
        }
    }
}