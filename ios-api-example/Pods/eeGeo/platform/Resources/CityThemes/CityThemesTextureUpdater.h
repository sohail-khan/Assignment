// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Helpers.h"
#include "Web.h"
#include "CityThemes.h"
#include "WebLoadRequestCompletionCallback.h"
#include "GLHelpers.h"
#include <string>
#include <vector>
#include <map>
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemesTextureUpdater : protected Eegeo::NonCopyable
            {
            private:
                Rendering::EnvironmentTextures& m_environmentTextures;
                Eegeo::Helpers::ITextureFileLoader& m_textureLoader;
                Web::IWebLoadRequestFactory& m_webRequestFactory;
                Web::TWebLoadRequestCompletionCallback<CityThemesTextureUpdater> m_themeTextureDownloadedHandler;
                Eegeo::Helpers::IHttpCache& m_httpCache;
                
                const CityThemeData* m_pTargetThemeData;
                int m_themeTexturesStillToDownload;
                int m_currentThemeTexturesCount;
                bool m_textureLoadingFailed;
                
                struct TextureInfoRefs
                {
                    bool used;
                    Eegeo::Helpers::GLHelpers::TextureInfo info;
                };
                
                std::map<std::string, TextureInfoRefs> m_loadedTextures;
                Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
                
            public:
                CityThemesTextureUpdater(Rendering::EnvironmentTextures& environmentTextures,
                                         Web::IWebLoadRequestFactory& webRequestFactory,
                                         Eegeo::Helpers::ITextureFileLoader& textureLoader,
                                         Eegeo::Helpers::IHttpCache& httpCache
                                         );
                
                void DownloadThemeTextures(const CityThemeData& targetTheme);
                bool IsLoading() const { return m_themeTexturesStillToDownload > 0; }
                int CurrentThemeTexturesToLoad() const { return m_currentThemeTexturesCount; }
                int CurrentThemeTexturesLoaded() const { return m_currentThemeTexturesCount - m_themeTexturesStillToDownload; }
                bool LoadsFailed() const { return m_textureLoadingFailed; }
                void CleanupRedundantLoads();
                void ApplyThemeTextures(const CityThemeData& themeData);
                
            private:
                void ThemeTextureDownloadedHandler(Eegeo::Web::IWebResponse& webResponse);
                void BeginTextureDownload(const std::string& textureName);
                void BeginTextureDownloads(const std::vector<std::string>& textureUrls);
                
                void LoadTextureFromBuffer(const std::string& url,
                                           const std::vector<Byte>& buffer);

                void LoadTextureFromResource(const std::string& url);

                Rendering::EnvironmentTexture* GetAndUseEnvironmentTexture(const std::string& textureFilename);
            };
            
            
        }
    }
}
