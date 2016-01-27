// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "TrafficCongestionLevel.h"
#include <map>

namespace Eegeo
{
    namespace TrafficCongestion
    {
        struct CongestionSettings : Eegeo::NonCopyable
        {
            float SpeedMultiplier;
            float VehicleSpacing;

            CongestionSettings(
                    float speedMultiplier,
                    float vehicleSpacing)
            :
            SpeedMultiplier(speedMultiplier),
            VehicleSpacing(vehicleSpacing)
            {

            }
        };

        class TrafficCongestionConfig
        {
        public:
            TrafficCongestionConfig();
            ~TrafficCongestionConfig();

            const CongestionSettings & GetSettingsForLevel(CongestionLevel::CongestionLevelValues level) const;

        private:
            typedef std::map<CongestionLevel::CongestionLevelValues, CongestionSettings *> TCongestionLevelToConfig;
            TCongestionLevelToConfig m_levelToConfiguration;
        };
    }
}