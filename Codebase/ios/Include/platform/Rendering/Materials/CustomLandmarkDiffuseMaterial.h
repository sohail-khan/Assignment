// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PackedDiffuseMaterial.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "Lighting.h"
#include "PackedDiffuseAlphaShader.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class CustomLandmarkDiffuseMaterial : public IMaterial
            {
            public:
                CustomLandmarkDiffuseMaterial(
                                      const TMaterialId materialId,
                                      const std::string& name,
                                      Shaders::PackedDiffuseAlphaShader& shader,
                                      const Lighting::GlobalLighting& lighting,
                                      Rendering::TextureMinifyType textureMinifyType,
                                      bool useAlternativeAmbient,
                                      bool textureRepeat);
                
                bool IsUsingAlternativeAmbient() const { return m_useAlternativeAmbient; }
                void UseAlternativeAmbient(bool useAlternativeAmbient) { m_useAlternativeAmbient = useAlternativeAmbient; }
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                void SetLandmarkPostfix(const std::string& postfix);
            private:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::PackedDiffuseAlphaShader& m_shader;
                const Lighting::GlobalLighting& m_lighting;
                Rendering::TextureMinifyType m_textureMinifyType;
                bool m_textureRepeat;
                bool m_useAlternativeAmbient;
                
                std::string m_currentThemeStateLandmarkPostfix;
            };
        }
    }
}
