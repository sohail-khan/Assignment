// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "GLHelpers.h"
#include "Lighting.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            class EnvironmentMaterialModule : protected Eegeo::NonCopyable
            {
                Eegeo::Rendering::EnvironmentMaterialFactory* m_pEnvironmentMaterialFactory;
                Eegeo::Rendering::EnvironmentTextures* m_pEnvironmentTextures;
                
                EnvironmentMaterialModule(Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                          Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                          Lighting::GlobalLighting& globalLighting,
                                          Lighting::GlobalFogging& globalFogging,
                                          Lighting::GlobalShadowing& globalShadowing,
                                          GLuint placeHolderTextureId);
                
            public:
                static EnvironmentMaterialModule* Create(Core::RenderingModule& renderingModule,
                                                         Core::LightingModule& lightingModule,
                                                         Helpers::GLHelpers::TextureInfo& placeholderTexture);
                
                ~EnvironmentMaterialModule();
                
                Rendering::EnvironmentMaterialFactory& GetEnvironmentMaterialFactory() const;
                Rendering::EnvironmentMaterialRepository& GetEnvironmentMaterialRepository() const;
                Eegeo::Rendering::EnvironmentTextures &GetEnvironmentTextures() const;
            };
        }
    }
}
