// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IdTypes.h"
#include "PackedDiffuseTransitionMaterial.h"
#include "Lighting.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class CustomLandmarkDiffuseTransitionMaterial : public PackedDiffuseTransitionMaterial
            {
            public:
                CustomLandmarkDiffuseTransitionMaterial(
                                                const TMaterialId materialId,
                                                const std::string& name,
                                                Shaders::PackedDiffuseTransitionShader& shader,
                                                const Lighting::GlobalLighting& lighting,
                                                const Lighting::GlobalFogging& fogging,
                                                Rendering::TextureMinifyType textureMinifyType,
                                                bool useAlternativeAmbient,
                                                bool textureRepeat
                                                        );
                
                void SetState(Rendering::GLState& glState) const;
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                void SetLandmarkPostfix(const std::string& fromPostfix, const std::string& toPostfix);
                

                void SetFromDiffuseTexture(TTextureId textureId);
                TTextureId GetFromTextureId() const;
                void SetToDiffuseTexture(TTextureId textureId);
                TTextureId GetToTextureId() const;
                
            protected:
                std::string m_fromThemeStateLandmarkPostfix;
                std::string m_toThemeStateLandmarkPostfix;
            };
        }
    }
}