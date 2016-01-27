// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "Graphics.h"
#include "VectorMath.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            namespace TexturedUniformColoredShaderCode
            {
                const std::string PositionName = "Position";
                const std::string UVName = "UV";
                const std::string ModelViewProjectionMatrixName = "ModelViewProjectionMatrix";

                const std::string _vertexDecls =
                        "attribute highp vec3 "+PositionName+";\n"
                        "attribute mediump vec2 "+UVName+";\n"
                        "varying mediump vec2 DestinationUV;\n"
                        "uniform highp mat4 "+ModelViewProjectionMatrixName+";\n";

                const std::string DiffuseName = "Diffuse";
                const std::string ColorName = "ColorName";

                const std::string _fragmentDecls =
                        "varying mediump vec2 DestinationUV;\n"
                        "uniform sampler2D "+DiffuseName+";\n"
                        "uniform lowp vec4 "+ColorName+";\n";

                const std::string _vertexCode = "void main(void) { \n"
                        "DestinationUV = UV;\n"
                        "gl_Position = ModelViewProjectionMatrix * vec4(Position.xyz, 1.0);\n"
                        "}";

                const std::string _fragmentCode = "void main(void) { \n"
                        "gl_FragColor = "+ColorName+" * texture2D("+DiffuseName+", DestinationUV.xy);\n"
                        "}";
            }

            class TexturedUniformColoredShader : public Shader
            {
            public:
                static TexturedUniformColoredShader* Create(const TShaderId shaderId)
                {
                    return Eegeo_NEW(TexturedUniformColoredShader)(
                            shaderId,
                            TexturedUniformColoredShaderCode::_vertexDecls + TexturedUniformColoredShaderCode::_vertexCode,
                            TexturedUniformColoredShaderCode::_fragmentDecls + TexturedUniformColoredShaderCode::_fragmentCode
                    );
                }

                const GLuint GetDiffuseSamplerId() const { return 0; }

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
                    SetUniformTextureSampler(glState, GetDiffuseSamplerId(), m_diffuseTextureSamplerUniformLocation);
                }

            protected:
                TexturedUniformColoredShader(const TShaderId shaderId, const std::string& vertexShaderCode, const std::string& fragmentShaderCode) : Shader(shaderId)
                {
                    CompileProgram(vertexShaderCode, fragmentShaderCode);

                    m_mvpUniformLocation = GetUniformLocation(TexturedUniformColoredShaderCode::ModelViewProjectionMatrixName);
                    m_colorUniformLocation = GetUniformLocation(TexturedUniformColoredShaderCode::ColorName);
                    m_diffuseTextureSamplerUniformLocation = GetUniformLocation(TexturedUniformColoredShaderCode::DiffuseName);
                }

            private:
                GLuint m_mvpUniformLocation ;
                GLuint m_colorUniformLocation;
                GLuint m_diffuseTextureSamplerUniformLocation;
            };
        }
    }
}
