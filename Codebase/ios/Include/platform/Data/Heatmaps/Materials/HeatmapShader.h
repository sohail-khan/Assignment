//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "Graphics.h"
#include "VectorMath.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Data
    {
        namespace Heatmaps
        {
            namespace Materials
            {
                class HeatmapShader : public Rendering::Shader
                {
                public:
                    static HeatmapShader* Create(const Rendering::TShaderId shaderId);
                    
                    void SetMVP(const m44& mvp) const
                    {
                        const bool transpose = false;
                        SetUniformM44(mvp, m_mvpUniformLocation, transpose);
                    }
                    
                    void Use(Rendering::GLState& glState) const
                    {
                        UseProgram(glState);
                        SetUniformTextureSampler(glState, GetDiffuseSamplerId(), m_diffuseTextureSamplerUniformLocation);
                        SetUniformTextureSampler(glState, GetGradientSamplerId(), m_gradientTextureSamplerUniformLocation);
                    }
                    
                    void SetAlpha(const float& alpha) const
                    {
                        SetUniformFloat(alpha, m_alphaUniformLocation);
                    }
                    
                    void SetMinValueOffset(const float& offset) const
                    {
                        SetUniformFloat(offset, m_minValueOffsetUniformLocation);
                    }
                    
                    void SetMaxValueScale(const float& scale) const
                    {
                        SetUniformFloat(scale, m_maxValueScaleUniformLocation);
                    }
                    
                    const GLuint GetDiffuseSamplerId() const { return 0; }
                    const GLuint GetGradientSamplerId() const { return 1; }
                    
                protected:
                    HeatmapShader(
                                         const Rendering::TShaderId shaderId,
                                         const std::string& vertexShaderCode,
                                         const std::string& fragmentShaderCode);
                    
                private:
                    GLuint m_mvpUniformLocation;
                    GLuint m_diffuseTextureSamplerUniformLocation;
                    GLuint m_gradientTextureSamplerUniformLocation;
                    GLuint m_minValueOffsetUniformLocation;
                    GLuint m_maxValueScaleUniformLocation;
                    GLuint m_alphaUniformLocation;
                };
            }
        }
    }
}