// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Space.h"
#include "Web.h"
#include "WebLoadRequestCompletionCallback.h"
#include "EegeoSearch.h"
#include "ESearchQueryResult.h"
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            class AddressSearchService : public Web::IWebLoadRequestCompletionCallback, public Eegeo::NonCopyable
            {
                Web::IWebLoadRequestFactory& m_webRequestFactory;
                SearchServiceCredentials& m_credentials;
                Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
                
            public:
                AddressSearchService(Web::IWebLoadRequestFactory& webRequestFactory,
                                     SearchServiceCredentials& credentials);
                virtual ~AddressSearchService();
                
                SearchQueryResult::Value SearchForAddresses(const Space::LatLongAltitude& where,
                                                            IAddressSearchCallback& callback);
                
                virtual void operator()(Web::IWebResponse& webResponse);
            };
        }
    }
}