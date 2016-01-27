// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


namespace Eegeo
{
    namespace Search
    {
        class SearchComponent;
        
        namespace Service
        {
            class SearchService;
            class SearchServiceCredentials;
            
            class GeocodeAddressService;
            class IGeocodeAddressCallback;
            struct GeocodeAddressResult;
            
            class AddressSearchService;
            class IAddressSearchCallback;
            struct AddressSearchResult;
            
            class PoiSearchService;
            class IPoiSearchCallback;
            struct PoiSearchResult;
            class IPoiInfoCallback;
            struct PoiInfoResult;
        }
    }
}
