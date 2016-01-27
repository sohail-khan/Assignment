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
            class IPoiInfoCallback : public Eegeo::NonCopyable
            {
            public:
                virtual ~IPoiInfoCallback() { }
                
                virtual void HandlePoiInfoResults(const PoiInfoResult& result) = 0;
            };
        }
    }
}