// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Web.h"
#include "ESearchQueryResult.h"
#include "EegeoSearch.h"
#include "WebLoadRequestCompletionCallback.h"
#include <string>

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            class GeocodeAddressService : public Web::IWebLoadRequestCompletionCallback, public Eegeo::NonCopyable
            {
                Web::IWebLoadRequestFactory& m_webRequestFactory;
                SearchServiceCredentials& m_credentials;
                
            public:
                GeocodeAddressService(Web::IWebLoadRequestFactory& webRequestFactory,
                                      SearchServiceCredentials& credentials);
                
                virtual ~GeocodeAddressService();
                
                SearchQueryResult::Value GeoCodeAddress(const std::string& address,
                                                        IGeocodeAddressCallback& callback);
                
                virtual void operator()(Web::IWebResponse& webResponse);
            };
        }
    }
}
