// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include <vector>
#include <set>
#include "Types.h"
#include "Web.h"
#include "Rendering.h"
#include "AnimatedObjects.h"
#include "Helpers.h"
#include "VectorMath.h"
#include "HttpAsyncTextureLoader.h"
#include "POD.h"
#include "CityThemes.h"
#include "Models.h"
#include "ModelInfoRef.h"
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemesAnimatedObjectsLoader : protected Eegeo::NonCopyable
            {
            public:                
                CityThemesAnimatedObjectsLoader(
                                                Web::IWebLoadRequestFactory& webRequestFactory,
                                                Eegeo::Helpers::IHttpCache& httpCache,
                                                Eegeo::Rendering::AsyncTexturing::HttpAsyncTextureLoader& asyncTextureLoader
                                                );
                
                ~CityThemesAnimatedObjectsLoader();
                
                void LoadAnimatedObjectsForTheme(const CityThemeData& theme);
                bool IsLoading() const { return m_modelsStillToDownload > 0; }
                bool LoadsFailed() const { return m_modelLoadingFailed; }
                void CleanupRedundantLoads();
                void RegisterAnimatedObjectsObserver(ICityThemeAnimatedObjectsObserver& observer);
                void UnregisterAnimatedObjectsObserver(ICityThemeAnimatedObjectsObserver& observer);
                void ApplyTheme();
                
            private:
                Web::IWebLoadRequestFactory& m_webRequestFactory;
                Web::TWebLoadRequestCompletionCallback<CityThemesAnimatedObjectsLoader> m_modelDownloadedHandler;
                Eegeo::Helpers::IHttpCache& m_httpCache;
                Eegeo::Rendering::AsyncTexturing::HttpAsyncTextureLoader& m_asyncTextureLoader;
                
                const CityThemeData* m_pTargetThemeData;
                int m_modelsStillToDownload;
                bool m_modelLoadingFailed;
                
                std::map<std::string, ModelInfoRef> m_loadedModels;
                std::vector<ICityThemeAnimatedObjectsObserver*> m_observers;
                Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
                std::set<ModelInfoRef*> m_pendingRequestInfoRefs;

                void ModelDownloadedHandler(Eegeo::Web::IWebResponse& webResponse);
                void BeginAnimatedObjectDownload(const CityThemeAnimationData &animationData);
                void LoadModelFromBuffer(const std::string& url, const std::vector<Byte>& buffer, ModelInfoRef modelInfoRef);
                std::string CreateTextureUrl(const std::string modelUrl, const std::string textureNameWithoutExtension) const;
                Eegeo::Rendering::AsyncTexturing::TIAsyncTextures LoadTexturesFromPODFile(const std::string& modelUrl, const IO::POD::PODFile& podFile);
            };
        }
    }
}
