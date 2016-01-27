// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IDiffuseMaterial.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "Lighting.h"
#include "PackedDiffuseFoggedShader.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class PackedDiffuseFoggedMaterial : protected Eegeo::NonCopyable, public IDiffuseMaterial
            {
            public:
                PackedDiffuseFoggedMaterial(
                                      const TMaterialId materialId,
                                      const std::string& name,
                                      Shaders::PackedDiffuseFoggedShader& shader,
                                      const Lighting::GlobalLighting& lighting,
                                      const Lighting::GlobalFogging& fogging,
                                      TTextureId textureId,
                                      Rendering::TextureMinifyType textureMinifyType,
                                      bool useAlternativeAmbient,
                                      bool textureRepeat
                                    );
                
                bool IsUsingAlternativeAmbient() const { return m_useAlternativeAmbient; }
                void UseAlternativeAmbient(bool useAlternativeAmbient) { m_useAlternativeAmbient = useAlternativeAmbient; }
                    
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetDiffuseTexture(TTextureId textureId) { m_textureId = textureId; }
                TTextureId GetTextureId() const { return m_textureId; }
                
                void SetState(Rendering::GLState& glState) const;
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::PackedDiffuseFoggedShader& m_shader;
                const Lighting::GlobalLighting& m_lighting;
                const Lighting::GlobalFogging& m_fogging;
                TTextureId m_textureId;
                Rendering::TextureMinifyType m_textureMinifyType;
                bool m_useAlternativeAmbient;
                bool m_textureRepeat;
            };
        }
    }
}
