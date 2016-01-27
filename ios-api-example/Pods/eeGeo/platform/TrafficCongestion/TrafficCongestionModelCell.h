// Copyright (c) 2014 eeGeo. All rights reserved.
#pragma once

#include "Types.h"
#include "TrafficCongestionConfig.h"
#include "MortonKey.h"

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class TrafficCongestionModelCell : protected Eegeo::NonCopyable
        {
        public:
            typedef std::map<int, Eegeo::TrafficCongestion::CongestionLevel::CongestionLevelValues> TRoadIdToSeverity;

            TrafficCongestionModelCell(const Streaming::MortonKey& m_key)
            : m_key(m_key)
            {

            }

            inline const Streaming::MortonKey& GetKey() const
            {
                return m_key;
            }

            void SetCongestion(
                    const int roadId,
                    const Eegeo::TrafficCongestion::CongestionLevel::CongestionLevelValues severity);

            const TrafficCongestionModelCell::TRoadIdToSeverity& GetData() const;

        private:
            Eegeo::Streaming::MortonKey m_key;
            TRoadIdToSeverity m_roadIdToSeverity;
        };
    }
}