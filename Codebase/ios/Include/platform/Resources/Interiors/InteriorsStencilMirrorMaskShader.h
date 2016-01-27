// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Interiors.h"
#include "Shader.h"
#include "ShaderMacros.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsStencilMirrorMaskShader : public Rendering::Shader
            {
            public:
                static InteriorsStencilMirrorMaskShader* Create(const Rendering::TShaderId shaderId);

                virtual void SetMVP(const m44& mvp) const {;}
                virtual void SetUnpackModelViewProjectionMatrix(const m44& unpackModelViewProjectionMatrix) const;
                virtual void SetColor(const v4& color) const;
                virtual void Use(Rendering::GLState& glState) const;

            protected:
                InteriorsStencilMirrorMaskShader(
                        const Rendering::TShaderId shaderId,
                        const std::string& vertexShaderCode,
                        const std::string& fragmentShaderCode);

            private:
                GLuint m_unpackModelViewProjectionMatrixUniformLocation;
                GLuint m_colorUniformLocation;
            };
        }
    }
}

