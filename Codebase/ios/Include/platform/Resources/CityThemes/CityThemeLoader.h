// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include <vector>
#include "Types.h"
#include "ICallback.h"
#include "CityThemes.h"
#include "Web.h"
#include "CityThemeLoader.h"
#include "WebLoadRequestCompletionCallback.h"
#include "PendingWebRequestsContainer.h"
#include "IWorkPool.h"
#include "ICityThemeChangedObserver.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            namespace LoaderState
            {
                enum Values
                {
                    NotStarted,
                    InProgress,
                    Completed,
                    Failed
                };
            }

            class CityThemeLoader : public ICityThemeChangedObserver, protected Eegeo::NonCopyable
            {
            public:
                CityThemeLoader(const std::string& streamedThemeNameContains,
                                const std::string& streamedThemeStateName,
                                Web::IWebLoadRequestFactory& webRequestFactory,
                                Concurrency::Tasks::IWorkPool& workPool,
                                CityThemeRepository& repository,
                                ICityThemesUpdater& cityThemesUpdater,
                                ICityThemesService& cityThemesService);

                ~CityThemeLoader();
                
                void LoadThemes(const std::string& url);

                LoaderState::Values GetState() const;

                bool IsStreaming() const;
                
                void QueueThemeToLoad(CityThemeData* themeToLoad);
                void LoadNextQueuedTheme();
                bool HasThemesToLoad() const;
                
                void OnThemeRequested(const CityThemeData& newTheme) { };
                void OnThemeChanged(const CityThemeData& newTheme);
                
            private:
                void WebLoadCompletedHandler(Eegeo::Web::IWebResponse& webResponse);
                
                void AllThemesLoaded();

                Web::IWebLoadRequestFactory& m_webRequestFactory;
                Concurrency::Tasks::IWorkPool& m_workPool;
                CityThemeRepository& m_repository;
                ICityThemesUpdater& m_cityThemesUpdater;
                ICityThemesService& m_cityThemesService;
                
                LoaderState::Values m_state;
                Web::TWebLoadRequestCompletionCallback<CityThemeLoader> m_webLoadFinishedHandler;
                Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;

                const std::string m_streamedThemeNameContains;
                const std::string m_streamedThemeStateName;

                bool m_switchedToInitialStreamedTheme;
                std::vector<CityThemeData*> m_themesToLoad;
            };
        }
    }
}
