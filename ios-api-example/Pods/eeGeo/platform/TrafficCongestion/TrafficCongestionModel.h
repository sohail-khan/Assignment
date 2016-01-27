// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "TrafficCongestion.h"
#include "TrafficCongestionConfig.h"
#include "MortonKey.h"
#include "TrafficCongestionModelCell.h"

#include <map>
#include <vector>

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class TrafficCongestionModel : protected Eegeo::NonCopyable
        {
        public:
            typedef std::map<Eegeo::Streaming::MortonKey, TrafficCongestionModelCell*, Streaming::MortonKeyCompare> TKeyToModelCell;
            typedef std::vector<ITrafficCongestionStateChangedCallback*> TCallbacks;

            void RegisterCongestionChangedCallback(ITrafficCongestionStateChangedCallback* callback);

            void UnregisterCongestionChangedCallback(ITrafficCongestionStateChangedCallback* callback);

            void SetCongestion(
                    const Eegeo::Streaming::MortonKey& key,
                    const int roadId,
                    const Eegeo::TrafficCongestion::CongestionLevel::CongestionLevelValues severity);

            bool TryGetCell(
                    const Streaming::MortonKey& key,
                    const TrafficCongestion::TrafficCongestionModelCell*& out_pCell) const;

        private:
            TKeyToModelCell m_keyToModelCell;
            TCallbacks m_callbacks;
        };
    }
}
