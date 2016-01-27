//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "VectorMathDecl.h"
#include "Graphics.h"
#include <string>

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            namespace Materials
            {
                class StencilAreaShader : public Rendering::Shader
                {
                public:
                    static StencilAreaShader* Create(const Rendering::TShaderId shaderId);
                    
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
                    StencilAreaShader(
                                        const Rendering::TShaderId shaderId,
                                        const std::string& vertexShaderCode,
                                        const std::string& fragmentShaderCode);
                    
                private:
                    GLuint m_mvpUniformLocation;
                };
            }
        }
    }
}