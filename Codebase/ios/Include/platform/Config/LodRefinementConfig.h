// Copyright eeGeo Ltd (2012-2014), All Rights Reserved
#pragma once

#include "ConfigSections.h"
#include <vector>

namespace Eegeo
{
    namespace Config
    {
        class LodRefinementConfig
        {
            static const double veryLowSpecLodRefinementAltitudes[];
            static const double lowSpecLodRefinementAltitudes[];
            static const double defaultLodRefinementAltitudes[];
        public:
            static const std::vector<double> GetLodRefinementAltitudesForDeviceSpec(Config::DeviceSpec deviceSpec);
        };
    }
}