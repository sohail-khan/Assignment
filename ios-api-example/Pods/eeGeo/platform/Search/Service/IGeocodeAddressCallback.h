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
            class IGeocodeAddressCallback : public Eegeo::NonCopyable
            {
            public:
                virtual ~IGeocodeAddressCallback() { }
                
                virtual void HandleGeocodeAddressResults(const GeocodeAddressResult& result) = 0;
            };
        }
    }
}
