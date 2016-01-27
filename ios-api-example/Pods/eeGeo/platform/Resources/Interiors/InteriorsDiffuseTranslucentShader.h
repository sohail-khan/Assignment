// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Shader.h"
#include "ShaderMacros.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsDiffuseTranslucentShader : public Rendering::Shader
            {
            public:
                static InteriorsDiffuseTranslucentShader* Create(const Rendering::TShaderId shaderId);
                
                virtual void SetMVP(const m44& mvp) const {;}
                void SetUnpackModelViewProjectionMatrix(const m44& unpackModelViewProjectionMatrix) const;
                void SetNormalToWorldMatrix(const m44& normalToWorldMatrix) const;
                
                void SetDiffuseColor(const v4& color) const;
                void SetLightColors(const m44& colors) const;
                void SetWorldToLightDirections(const m44& worldSpaceToLightDirections) const;
                
                void Use(Rendering::GLState& glState) const;
                
                GLuint GetDiffuseSamplerId() const { return 0; }

            protected:
                InteriorsDiffuseTranslucentShader(
                                               const Rendering::TShaderId shaderId,
                                               const std::string& vertexShaderCode,
                                               const std::string& fragmentShaderCode);
                
            private:
                GLuint m_unpackModelViewProjectionMatrixUniformLocation;
                GLuint m_normalToWorldMatrixUniformLocation;
                
                GLuint m_lightColorsUniformLocation;
                GLuint m_worldToLightDirectionsUniformLocation;
                
                GLuint m_diffuseColorUniformLocation;
            };
        }
    }
}
