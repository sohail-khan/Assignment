// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PackedDiffuseFoggedMaterial.h"
#include "IdTypes.h"
#include "Lighting.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class CustomLandmarkDiffuseFoggedMaterial : public PackedDiffuseFoggedMaterial
            {
            public:
                CustomLandmarkDiffuseFoggedMaterial(
                                            const TMaterialId materialId,
                                            const std::string& name,
                                            Shaders::PackedDiffuseFoggedShader& shader,
                                            const Lighting::GlobalLighting& lighting,
                                            const Lighting::GlobalFogging& fogging,
                                            Rendering::TextureMinifyType textureMinifyType,
                                            bool useAlternativeAmbient,
                                            bool textureRepeat
                                                    );
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                void SetLandmarkPostfix(const std::string& postfix);
                
                void SetDiffuseTexture(TTextureId textureId);
                TTextureId GetTextureId() const;
            private:
                std::string m_currentThemeStateLandmarkPostfix;
            };
        }
    }
}
