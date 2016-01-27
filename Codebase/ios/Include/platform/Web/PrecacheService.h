// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Web.h"
#include "Streaming.h"
#include "Helpers.h"
#include "WebLoadRequestCompletionCallback.h"
#include "ICityThemesService.h"
#include "IWebLoadRequest.h"
#include "CallbackCollection.h"
#include <vector>
#include <string>
#include <deque>
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Streaming
    {
        class IStreamingVolume;
    }
    
    namespace Web
    {
        class PrecacheService : protected Eegeo::NonCopyable
        {
        public:
            PrecacheService(IWebLoadRequestFactory* webLoadRequestFactory,
                            Eegeo::Streaming::PayloadSlotStreamMap *pPayloadSlotStreamMap,
                            Eegeo::Helpers::IHttpCache* m_pCache,
                            Resources::CityThemes::ICityThemesService& cityThemeService);
            
            int TotalUrlsToLoad() const { return m_totalUrlsToLoad; }
            int UrlsErrored() const { return m_erroredRequests; }
            int Urls404ed() const { return m_fourOhFourRequests; }
            int UrlsLoaded() const { return TotalUrlsToLoad() - m_numberUrlsRemainingLoad; }

            float PercentCompleted() const;
            bool CurrentlyPrecaching() const { return m_numberUrlsRemainingLoad > 0; }
            bool IsCancelling() const { return false; }
            
            void CancelPrecaching();
            
            bool CanPrecache(double altitude);
            void Precache(Streaming::IStreamingVolume& volume);
            void IssueRequests();
            uint EstimatedPrecacheSizekB(Streaming::IStreamingVolume& volume);
            
            void InsertPrecacheCancelledCallback(Eegeo::Helpers::ICallback0& callback);
            
            void RemovePrecacheCancelledCallback(Eegeo::Helpers::ICallback0& callback);
            
            void InsertPrecacheCompletedCallback(Eegeo::Helpers::ICallback0& callback);
            
            void RemovePrecacheCompletedCallback(Eegeo::Helpers::ICallback0& callback);
        private:
            
            const static int MAX_PRECACHE_REQUESTS_IN_FLIGHT = 10;

            int m_totalUrlsToLoad;
            int m_numberUrlsRemainingLoad;
            int m_requestsInFlightCount;
            int m_erroredRequests;
            int m_fourOhFourRequests;
            
            std::deque<std::string> m_requestsToIssue;
            
            Eegeo::Helpers::IHttpCache* m_pCache;
            IWebLoadRequestFactory* m_webLoadRequestFactory;
            Eegeo::Streaming::PayloadSlotStreamMap *m_pPayloadSlotStreamMap;
            Resources::CityThemes::ICityThemesService& m_cityThemeService;
            
            TWebLoadRequestCompletionCallback<PrecacheService> m_webLoadRequestCompletionCallback;
            
            Eegeo::Helpers::CallbackCollection0 m_preloadCancelledCallbacks;
            Eegeo::Helpers::CallbackCollection0 m_preloadCompletedCallbacks;
            
            Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
            
            void EnqueueRequest(const std::string& url);
            void PrecacheCustomBuildingTextures(const Web::TResourceData* data);
            void OnWebLoadRequestCompleted(IWebResponse& webResponse);
            std::vector<Streaming::MortonKey> GetCellsIntersectingVolume(Streaming::IStreamingVolume& volume);
        };
    }
}
