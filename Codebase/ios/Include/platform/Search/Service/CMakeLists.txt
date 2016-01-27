set(headers ${headers} platform/Search/Service
)
set(currsources
  platform/Search/Service/AddressSearchResult.h
  platform/Search/Service/AddressSearchService.cpp
  platform/Search/Service/AddressSearchService.h
  platform/Search/Service/CMakeLists.txt
  platform/Search/Service/ESearchQueryResult.h
  platform/Search/Service/GeocodeAddressResult.h
  platform/Search/Service/GeocodeAddressService.cpp
  platform/Search/Service/GeocodeAddressService.h
  platform/Search/Service/IAddressSearchCallback.h
  platform/Search/Service/IGeocodeAddressCallback.h
  platform/Search/Service/IPoiInfoCallback.h
  platform/Search/Service/IPoiSearchCallback.h
  platform/Search/Service/PoiInfoResult.h
  platform/Search/Service/PoiSearchResult.h
  platform/Search/Service/PoiSearchService.cpp
  platform/Search/Service/PoiSearchService.h
  platform/Search/Service/SearchService.cpp
  platform/Search/Service/SearchService.h
  platform/Search/Service/SearchServiceCredentials.h
)
set(sources ${sources} ${currsources})
source_group(\\Search\\Service FILES ${currsources})
