// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IAsyncTexture.h"
#include "GLHelpers.h"
#include "Web.h"
#include "AsyncTexturing.h"
#include <string>
#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace AsyncTexturing
        {
            class HttpAsyncTexture : protected Eegeo::NonCopyable, public IAsyncTexture
            {
            public:
                HttpAsyncTexture(HttpAsyncTextureLoader& asyncTextureLoader,
                                 const std::string& textureUrl,
                                 const Eegeo::Helpers::GLHelpers::TextureInfo& initialTexInfo,
                                 Rendering::EnvironmentTexture* pPlaceholderTexture,
                                 IAsyncTextureObserver* pObserver,
                                 bool tryToUpdateIfModified=false);
                ~HttpAsyncTexture();

                void Release();
                const std::string GetUrl() const;
                const Helpers::GLHelpers::TextureInfo& GetTextureInfo() const;
                bool IsLoaded() const;
                bool IsComplete() const;
                bool IsTryToUpdateIfModified() const;

                
                int GetReferenceCount() const;
                void IncrementReferenceCount();
                void DecrementReferenceCount();
                void SetWebLoadRequest(Eegeo::Web::IWebLoadRequest& webLoadRequest);
                void ClearWebLoadRequest();
                void SetLoadedTexture(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfoToSet);
                
            private:
                HttpAsyncTextureLoader& m_asyncTextureLoader;
                std::string m_url;
                Eegeo::Helpers::GLHelpers::TextureInfo m_textureInfo;
                Rendering::EnvironmentTexture* m_pPlaceholderTexture;
                IAsyncTextureObserver* m_pObserver;
                int m_referenceCount;
                bool m_isLoaded;
                bool m_isComplete;
                bool m_tryToUpdateIfModified;
                Eegeo::Web::IWebLoadRequest* m_pWebLoadRequest;
            };
        }
    }
}
