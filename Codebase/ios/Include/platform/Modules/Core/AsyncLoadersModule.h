// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "AsyncTexturing.h"
#include "AsyncModels.h"
#include "Web.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class AsyncLoadersModule : Eegeo::NonCopyable
            {
            public:
                AsyncLoadersModule(Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                   Helpers::IHttpCache& httpCache,
                                   Helpers::ITextureFileLoader& textureLoader,
                                   const Helpers::GLHelpers::TextureInfo& placeholderTextureInfo
                                   );
                
                
                ~AsyncLoadersModule();
                static AsyncLoadersModule* Create(Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                                  Helpers::IHttpCache& httpCache,
                                                  Helpers::ITextureFileLoader& textureLoader,
                                                  const Helpers::GLHelpers::TextureInfo& placeholderTextureInfo);
                
                Rendering::AsyncTexturing::HttpAsyncTextureLoader& GetHttpAsyncTextureLoader() const;
                Rendering::AsyncTexturing::LocalAsyncTextureLoader& GetLocalAsyncTextureLoader() const;
            private:
                Rendering::AsyncTexturing::HttpAsyncTextureLoader* m_pHttpAsyncTextureLoader;
                Rendering::AsyncTexturing::LocalAsyncTextureLoader* m_pLocalAsyncTextureLoader;
            };
        }
    }
}