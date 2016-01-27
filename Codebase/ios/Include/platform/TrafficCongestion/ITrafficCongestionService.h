// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "TrafficCongestionConfig.h"

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class ITrafficCongestionService
        {
        public:
            virtual ~ITrafficCongestionService() {}

            virtual void SetCongestionFor(
                    const Streaming::MortonKey& key,
                    const int roadId,
                    const CongestionLevel::CongestionLevelValues congestionLevel) = 0;
        };
    }
}

