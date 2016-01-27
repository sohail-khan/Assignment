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
            class IAddressSearchCallback : public Eegeo::NonCopyable
            {
            public:
                virtual ~IAddressSearchCallback() { }
                
                virtual void HandleAddressSearchResults(const AddressSearchResult& result) = 0;
            };
        }
    }
}
