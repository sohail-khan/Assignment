// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IAsyncTextureRequestor.h"
#include "Web.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "IdTypes.h"
#include "WebLoadRequestCompletionCallback.h"
#include <map>
#include <deque>
#include <string>
#include <vector>
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace AsyncTexturing
        {
            typedef std::vector<Rendering::AsyncTexturing::IAsyncTexture*> TIAsyncTextures;
            
            class HttpAsyncTextureLoader : protected Eegeo::NonCopyable, public IAsyncTextureRequestor
            {
            public:
               HttpAsyncTextureLoader(
                                      Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                      Eegeo::Helpers::IHttpCache& httpCache,
                                      Eegeo::Helpers::ITextureFileLoader& textureLoader,
                                      const Eegeo::Helpers::GLHelpers::TextureInfo& placeholderTextureInfo
                                      );

                IAsyncTexture& RequestTexture(const std::string& textureUrl, IAsyncTextureObserver* pObserver, bool tryToUpdateIfModified=false);
                void Release(const HttpAsyncTexture& textureToRelease);
                
                void IssueNextLoadRequest();
                bool HasPendingLoadRequests() const;
                void UpdatePlaceholderEnvironmentTexture(Rendering::EnvironmentTexture* pTexture);
                              
            private:
                Web::IWebLoadRequestFactory& m_webLoadRequestFactory;
                Eegeo::Helpers::IHttpCache& m_httpCache;
                Eegeo::Helpers::ITextureFileLoader& m_textureLoader;
                Eegeo::Helpers::GLHelpers::TextureInfo m_placeholderTextureInfo;
                Rendering::EnvironmentTexture* m_pPlaceholderEnvironmentTexture;
              
                typedef std::deque<HttpAsyncTexture*> TTextureDeque;
                TTextureDeque m_pendingLoads;
                int m_inFlightLoadCount;
              
                typedef std::map<std::string, HttpAsyncTexture*> TStringToTexture;
                TStringToTexture m_texturesByUrl;
              
                Web::TWebLoadRequestCompletionCallback<HttpAsyncTextureLoader> m_webRequestCompletionCallback;
                Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
              
                HttpAsyncTexture* CreateTexture(const std::string& textureUrl, IAsyncTextureObserver* pObserver, bool tryToUpdateIfModified);
                HttpAsyncTexture* GetTextureByUrl(const std::string& textureUrl) const;
                bool Contains(const std::string& textureUrl) const;
                void Evict(HttpAsyncTexture* pTexture);
                void StartLoadingTexture(HttpAsyncTexture* pTexture);
                void OnWebLoadComplete(Web::IWebResponse& webResponse);
                bool LoadTextureFromBuffer(const std::vector<Byte>* pBuffer, const std::string& textureUrl, Eegeo::Helpers::GLHelpers::TextureInfo& textureInfoToPopulate);

                typedef std::map<HttpAsyncTexture*, Web::IWebLoadRequest*> TTextureToRequest;
                TTextureToRequest m_requestByTexture;
                
            };
        }
    }
}
