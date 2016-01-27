// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewShader : public Rendering::Shader
            {
            public:
                static RouteViewShader* Create(const Rendering::TShaderId shaderId);
                
                RouteViewShader(const Rendering::TShaderId shaderId, const std::string& vertexCode, const std::string& fragmentCode);
                
                void Use(Rendering::GLState& glState) const
                {
                    UseProgram(glState);
                }
                
                void SetMVP(const m44& mvp) const
                {
                    bool transpose = false;
                    SetUniformM44(mvp, m_modelViewProjectionUniform, transpose);
                }
                
                void SetAltitudeFade(float fade) const
                {
                    SetUniformFloat(fade, m_altitudeFadeUniform);
                }

                void SetThickness(float thickness) const
                {
                    SetUniformFloat(thickness, m_thicknessUniform);
                }
                
            private:
                GLuint m_modelViewProjectionUniform;
                GLuint m_altitudeFadeUniform;
                GLuint m_thicknessUniform;
            };
        }
    }
}
