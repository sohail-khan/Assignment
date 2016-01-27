// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

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
            class InteriorsCubeMappedShader : public Rendering::Shader
            {
            public:
                static InteriorsCubeMappedShader* Create(const Rendering::TShaderId shaderId);
                
                virtual void SetMVP(const m44& mvp) const {;}
                void SetUnpackModelViewProjectionMatrix(const m44& unpackModelViewProjectionMatrix) const;
                void SetUnpackModelMatrix(const m44& unpackModelMatrix) const;
                void SetNormalToWorldMatrix(const m44& normalToWorldMatrix) const;
                void SetDiffuseColor(const v4& color) const;
                void SetReflectionColor(const v3& color) const;
                void SetLightColors(const m44& colors) const;
                void SetWorldToLightDirections(const m44& worldSpaceToLightDirections) const;
                void SetUVBounds(const Eegeo::v2& min, const Eegeo::v2& max) const;
                void SetWorldToEcefTangentMatrix(const m44& worldToEcefTangentMatrix) const;
                void SetViewOffset(const v3& viewDirection, float offsetParam) const;
                
                void Use(Rendering::GLState& glState) const;
                
                GLuint GetDiffuseSamplerId() const { return m_diffuseSamplerId; }
                
                GLuint GetCubeMapSamplerId() const { return m_cubeMapSamplerId; }
                
                
                
            protected:
                InteriorsCubeMappedShader(
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
                GLuint m_reflectionColorUniformLocation;
                
                GLuint m_cubeMapSamplerUniformLocation;
                GLuint m_worldToEcefTangentMatrixUniformLocation;
                
                GLuint m_viewOffsetUniformLocation;
                
                const GLuint m_diffuseSamplerId;
                const GLuint m_cubeMapSamplerId;
            };
        }
    }
}