// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "ITrafficCongestionService.h"
#include "TrafficCongestion.h"

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class TrafficCongestionService : public ITrafficCongestionService
        {
        public:
            TrafficCongestionService(TrafficCongestionModel& model)
            : m_model(model)
            {

            }

            virtual void SetCongestionFor(
                    const Streaming::MortonKey& key,
                    const int roadId,
                    const CongestionLevel::CongestionLevelValues congestionLevel);

        private:
            TrafficCongestionModel& m_model;
        };
    }
}

