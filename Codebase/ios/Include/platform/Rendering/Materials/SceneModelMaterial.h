// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ModelMaterial.h"
#include "Types.h"
#include "Rendering.h"
#include "GlobalLighting.h"
#include "GlobalFogging.h"
#include "TextureMinifyType.h"
#include "ModelShader.h"
#include "SceneModelTextureResource.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class SceneModelMaterial : public ModelMaterial
            {
            public:

                SceneModelMaterial(const TMaterialId materialId,
                                   const std::string& name,
                                   Shaders::ModelShader& shader,
                                   const Lighting::GlobalLighting& lighting,
                                   const Lighting::GlobalFogging& fogging,
                                   SceneModels::SceneModelTextureResource& sceneModelTexture,
                                   Rendering::TextureMinifyType textureMinifyType,
                                   bool textureRepeat);
                ~SceneModelMaterial();
                
                void SetDiffuseTexture(TTextureId textureId);
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                TTextureId GetTextureId() const { return m_textureResource.GetTexture(); }

            private:
                
                SceneModels::SceneModelTextureResource& m_textureResource;
            };
        }
    }
}