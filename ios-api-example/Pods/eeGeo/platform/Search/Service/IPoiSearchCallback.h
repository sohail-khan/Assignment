// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "EegeoSearch.h"

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            class IPoiSearchCallback : public Eegeo::NonCopyable
            {
            public:
                virtual ~IPoiSearchCallback() { }
                
                virtual void HandlePoiSearchResults(const PoiSearchResult& result) = 0;
            };
        }
    }
}