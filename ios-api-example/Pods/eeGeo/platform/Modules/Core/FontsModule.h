// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "Shader.h"
#include "EnvironmentCharacterSet.h"
#include "Helpers.h"
#include "Modules.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class FontsModule : protected Eegeo::NonCopyable
            {
            public:
                FontsModule(Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                            EnvironmentCharacterSet::Type characterSetType,
                            Helpers::IFileIO& fileIO,
                            Helpers::ITextureFileLoader& textureLoader);
                
                ~FontsModule();
                
                static FontsModule* Create(RenderingModule& renderingModule,
                                           EnvironmentCharacterSet::Type characterSetType,
                                           Helpers::IFileIO& fileIO,
                                           Helpers::ITextureFileLoader& textureLoader);
                
                Fonts::FontInstance& GetEnvironmentFont() const;
                Rendering::Shaders::TextShader& GetTextShader() const;
            private:
                Fonts::FontInstance* m_pEnvironmentFont;
                Rendering::Shaders::TextShader* m_pTextShader;
            };
        }
    }
}