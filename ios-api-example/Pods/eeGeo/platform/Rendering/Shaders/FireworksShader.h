// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "VectorMath.h"
#include "Graphics.h"
#include "ShaderMacros.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace FireworksShaderCode
            {
                const std::string PositionName = "Position";
                const std::string UVName = "UV";
                const std::string ModelViewProjectionMatrixName = "ModelViewProjectionMatrix";
                const std::string ColorName = "Color";
                const std::string ColorVaryingName = "ColorVarying";
                const std::string UVVaryingName = "UVVarying";
                const std::string DiffuseName = "Diffuse";
                
                const std::string _vertexDecls =
                "attribute mediump vec3 "+PositionName+";\n"
                "attribute mediump vec2 "+UVName+";\n"
                "attribute vec4 "+ColorName+";\n"
                "varying lowp vec4 "+ColorVaryingName+";\n"
                "varying mediump vec2 "+UVVaryingName+";\n"
                "uniform highp mat4 "+ModelViewProjectionMatrixName+";\n";
                
                const std::string _fragmentDecls =
                "varying lowp vec4 "+ColorVaryingName+";\n"
                "varying mediump vec2 "+UVVaryingName+";\n"
                "uniform sampler2D "+DiffuseName+";\n";
                
                const std::string _vertexCode =
                "void main(void) { \n"
                ""+ColorVaryingName+" = "+ColorName+";\n"
                ""+UVVaryingName+" = "+UVName+";\n"
                "gl_Position = "+ModelViewProjectionMatrixName+" * vec4(Position.xyz, 1.0);\n"
                "}";
                
                const std::string _fragmentCode =
                "void main(void) { \n"
                "lowp vec4 sampleCol = " TEXTURE2D(Diffuse, UVVarying) ".rgba;\n"
                "gl_FragColor.rgba = (sampleCol.rgba * mix(" + ColorVaryingName + ".rgba, vec4(1,1,1,1), sampleCol.r)) * "+ColorVaryingName+".a;\n"
                "}";
                
            }
            
            class FireworksShader : public Shader
            {
            public:
                static FireworksShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(FireworksShader)(
                                                        shaderId,
                                                        FireworksShaderCode::_vertexDecls + FireworksShaderCode::_vertexCode,
                                                        FireworksShaderCode::_fragmentDecls + FireworksShaderCode::_fragmentCode
                                                        );
                }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }
                
                GLuint GetPositionUniform() const { return GetVertexAttributes().GetElement(0).GetLocation(); }
                GLuint GetUVUniform() const { return GetVertexAttributes().GetElement(1).GetLocation(); }
                GLuint GetColorUniform() const { return GetVertexAttributes().GetElement(2).GetLocation(); }
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                }
                
            protected:
                FireworksShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);
                    m_mvpUniformLocation = GetUniformLocation(FireworksShaderCode::ModelViewProjectionMatrixName);
                }
                
                
                
            private:
                GLuint m_mvpUniformLocation;
            };
        }
    }
}