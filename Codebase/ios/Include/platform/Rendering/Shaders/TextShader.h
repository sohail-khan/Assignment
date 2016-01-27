// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Shader.h"
#include "IdTypes.h"
#include "Graphics.h"
#include "Rendering.h"
#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            class TextShader : public Shader
            {
            public:
                static TextShader* Create(const TShaderId shaderId);

                static TextShader* CreateWithOutline(const TShaderId shaderId);
                
                const GLuint GetDiffuseSamplerId() const;
                
                void SetMVP(const m44& mvp) const;
                
                void SetScale(const v3& scale) const;
                
                void SetForegroundColour(const v4& rgba);
                
                void SetShadowColour(const v4& rgba);
                
                void SetOutlineColour(const v4& rgba);
                
                void SetThresholds(const bool outlinedText);
                                             
                void Use(Rendering::GLState& glState) const;
                
            private:
                GLuint m_modelViewProjectionUniformLocation;
                GLuint m_scaleUniformLocation;
                GLuint m_foregroundColourUniformLocation;
                GLuint m_shadowColourUniformLocation;
                GLuint m_outlineColourUniformLocation;
                GLuint m_diffuseTextureSampleUniformLocation;
                GLuint m_thresholdsUniformLocation;
                
                const bool m_hasOutlineColourUniform;

                TextShader(const TShaderId shaderId, const std::string& vertexCode, const std::string& fragmentCode, bool hasOutlineColourUniform);
            };
        }
    }
}

