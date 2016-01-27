// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "DiffuseMaterial.h"
#include "IdTypes.h"
#include "DiffuseShader.h"
#include "Lighting.h"
#include "TextureMinifyType.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class UniqueDiffuseMaterial : public DiffuseMaterial
            {
            public:
                UniqueDiffuseMaterial(
                                const TMaterialId materialId,
                                const std::string& name,
                                Shaders::DiffuseShader& shader,
                                const Lighting::GlobalLighting& lighting,
                                TTextureId textureId,
                                Rendering::TextureMinifyType textureMinifyType,
                                bool useAlternativeAmbient,
                                bool textureRepeat
                                      );
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
            };
        }
    }
}