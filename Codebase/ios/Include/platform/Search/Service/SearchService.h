// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "UrlHelpers.h"
#include "Web.h"
#include "Space.h"
#include "EegeoSearch.h"
#include "ESearchQueryResult.h"
#include <string>

namespace Eegeo
{

    namespace Search
    {
        namespace Service
        {
            class SearchService : public Eegeo::NonCopyable
            {
                GeocodeAddressService* m_pGeocodeAddressService;
                AddressSearchService* m_pAddressSearchService;
                PoiSearchService* m_pPoiSearchService;
                Eegeo::Helpers::UrlHelpers::IUrlEncoder& m_urlEncoder;
                
            public:
                SearchService(Web::IWebLoadRequestFactory& webRequestFactory,
                              Helpers::UrlHelpers::IUrlEncoder& urlEncoder,
                              SearchServiceCredentials& credentials);
                virtual ~SearchService();
                
                SearchQueryResult::Value GeoCodeAddress(const std::string& address,
                                                        IGeocodeAddressCallback& callback);
             
                SearchQueryResult::Value SearchForAddresses(const Space::LatLongAltitude& where,
                                                            IAddressSearchCallback& callback);
                
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