// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "VectorMathDecl.h"
#include "Graphics.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            class VertexColoredShader : public Shader
            {
            public:
                static VertexColoredShader* Create(const TShaderId shaderId);

                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                }

                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                }

            protected:
                VertexColoredShader(
                        const TShaderId shaderId,
                        const std::string& vertexShaderCode,
                        const std::string& fragmentShaderCode);

            private:
                GLuint m_mvpUniformLocation;
            };
        }
    }
}
