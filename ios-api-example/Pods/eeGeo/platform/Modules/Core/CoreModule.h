// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "Web.h"
#include "EnvironmentCharacterSet.h"
#include "IdTypes.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class CoreModule : protected Eegeo::NonCopyable
            {
            public:
                CoreModule(
                           Helpers::IFileIO& fileIO,
                           Helpers::ITextureFileLoader& textureLoader,
                           Web::IWebLoadRequestFactory& webLoadRequestFactory,
                           Helpers::IHttpCache& httpCache,
                           const bool bufferPoolingEnabled,
                           EnvironmentCharacterSet::Type characterSetType,
                           Helpers::GLHelpers::TextureInfo& placeholderTextureInfo
                           );
                ~CoreModule();
                
                static CoreModule* Create(
                                          const Modules::IPlatformAbstractionModule& platformAbstractionModule,
                                          const bool bufferPoolingEnabled,
                                          EnvironmentCharacterSet::Type characterSetType,
                                          Helpers::GLHelpers::TextureInfo& placeholderTextureInfo
                                         );
                
                RenderingModule& GetRenderingModule() const;
                LightingModule& GetLightingModule() const;
                FontsModule& GetFontsModule() const;
                AsyncLoadersModule& GetAsyncLoadersModule() const;
                DebugRenderingModule& GetDebugRenderingModule() const;
                SceneModelsModule& GetSceneModelsModule() const;
                Rendering::TTextureId GetPlaceholderTextureId() const;
            private:
                RenderingModule* m_pRenderingModule;
                LightingModule* m_pLightingModule;
                FontsModule* m_pFontsModule;
                AsyncLoadersModule* m_pAsyncLoadersModule;
                DebugRenderingModule* m_pDebugRenderingModule;
                SceneModelsModule* m_pSceneModelsModule;
                const Rendering::TTextureId m_placeholderTextureId;
            };
        }
    }
}