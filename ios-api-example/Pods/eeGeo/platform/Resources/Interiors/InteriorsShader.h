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
            class InteriorsShader : public Rendering::Shader
            {
            public:
                static InteriorsShader* Create(const Rendering::TShaderId shaderId);

                virtual void SetMVP(const m44& mvp) const {;}
                void SetUnpackModelViewProjectionMatrix(const m44& unpackModelViewProjectionMatrix) const;
                void SetDiffuseColor(const v4& color) const;
                void SetLightColors(const m44& colors) const;
                void SetModelToLightDirections(const m44& modelSpaceToLightDirections) const;
                void Use(Rendering::GLState& glState) const;

            protected:
                InteriorsShader(
                        const Rendering::TShaderId shaderId,
                        const std::string& vertexShaderCode,
                        const std::string& fragmentShaderCode);

            private:
                GLuint m_unpackModelViewProjectionMatrixUniformLocation ;
                GLuint m_lightColorsUniformLocation;
                GLuint m_modelToLightDirectionsUniformLocation;
                GLuint m_diffuseColorUniformLocation;
            };
        }
    }
}

