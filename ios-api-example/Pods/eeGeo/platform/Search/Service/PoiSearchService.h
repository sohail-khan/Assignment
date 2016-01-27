// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "EegeoSearch.h"
#include "WebLoadRequestCompletionCallback.h"
#include "Web.h"
#include "Space.h"
#include "ESearchQueryResult.h"
#include <string>
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            class PoiSearchService : public Eegeo::NonCopyable
            {
                Web::TWebLoadRequestCompletionCallback<PoiSearchService>* m_poiSearchCallback;
                Web::TWebLoadRequestCompletionCallback<PoiSearchService>* m_poiInfoCallback;
                Web::IWebLoadRequestFactory& m_webRequestFactory;
                SearchServiceCredentials& m_credentials;
                Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
                
                void HandleSearchResponse(Web::IWebResponse& webResponse);
                void HandleInfoResponse(Web::IWebResponse& webResponse);
                
            public:
                PoiSearchService(Web::IWebLoadRequestFactory& webRequestFactory,
                                 SearchServiceCredentials& credentials);
                
                virtual ~PoiSearchService();
                
                SearchQueryResult::Value SearchForPoi(const std::string& query,
                                                      bool isCategory,
                                                      const Space::LatLongAltitude& where,
                                                      IPoiSearchCallback& callback);
                
                SearchQueryResult::Value SearchForPoiInfo(const std::string& placeId,
                                                          IPoiInfoCallback& callback);
                
            };
        }
    }
}