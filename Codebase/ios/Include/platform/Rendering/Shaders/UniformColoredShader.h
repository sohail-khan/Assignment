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
            class UniformColoredShader : public Shader
            {
            public:
                static UniformColoredShader* Create(const TShaderId shaderId);

                void SetMVP(const m44& mvp) const
                {
                    const bool transpose = false;
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
                UniformColoredShader(
                        const TShaderId shaderId,
                        const std::string& vertexShaderCode,
                        const std::string& fragmentShaderCode);

            private:
                GLuint m_mvpUniformLocation ;
                GLuint m_colorUniformLocation;
            };
        }
    }
}
