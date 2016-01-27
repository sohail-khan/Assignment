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
            class InteriorsDiffuseSpecularShader : public Rendering::Shader
            {
            public:
                static InteriorsDiffuseSpecularShader* Create(const Rendering::TShaderId shaderId);
                
                virtual void SetMVP(const m44& mvp) const {;}
                void SetUnpackModelViewProjectionMatrix(const m44& unpackModelViewProjectionMatrix) const;
                void SetUnpackModelMatrix(const m44& unpackModelMatrix) const;
                void SetNormalToWorldMatrix(const m44& normalToWorldMatrix) const;
                
                void SetDiffuseColor(const v4& color) const;
                void SetSpecularColor(const v3& color) const;
                void SetLightColors(const m44& colors) const;
                void SetWorldToLightDirections(const m44& worldSpaceToLightDirections) const;
                void SetUVBounds(const Eegeo::v2& min, const Eegeo::v2& max) const;
                void SetSpecularPower(float specularPower) const;
                void SetSpecularModulateTexture(float specularModulateTexture) const;
                void SetSpecularityFromTextureLuminance(float specularityFromTextureLuminance) const;
                void SetViewOffset(const v3& viewDirection, float offsetParam) const;
                
                void Use(Rendering::GLState& glState) const;
                
                GLuint GetDiffuseSamplerId() const { return 0; }
                
                
                
                
            protected:
                InteriorsDiffuseSpecularShader(
                                               const Rendering::TShaderId shaderId,
                                               const std::string& vertexShaderCode,
                                               const std::string& fragmentShaderCode);
                
            private:
                GLuint m_unpackModelViewProjectionMatrixUniformLocation;
                GLuint m_unpackModelMatrixUniformLocation;
                GLuint m_normalToWorldMatrixUniformLocation;
                
                GLuint m_lightColorsUniformLocation;
                GLuint m_worldToLightDirectionsUniformLocation;
                GLuint m_minUVRangeUniformLocation;
                GLuint m_maxUVRangeUniformLocation;
                GLuint m_diffuseTextureSamplerUniformLocation;
                
                GLuint m_diffuseColorUniformLocation;
                GLuint m_specularColorUniformLocation;
                GLuint m_specularPowerUniformLocation;
                GLuint m_specularModulateTextureUniformLocation;
                GLuint m_specularityFromTextureLuminanceUniformLocation;
                GLuint m_viewOffsetUniformLocation;
            };
        }
    }
}