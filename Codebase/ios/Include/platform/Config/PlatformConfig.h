// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ConfigSections.h"

namespace Eegeo
{
    namespace Config
    {
        struct PlatformConfig
        {
        public:
            CoverageTreeConfigSection CoverageTreeConfig;
            CityThemesConfigSection CityThemesConfig;
            GraphicsConfigSection GraphicsConfig;
            PerformanceConfigSection PerformanceConfig;
            CompatibilityConfigSection CompatibilityConfig;
            OptionsConfigSection OptionsConfig;
            MapLayersConfigSection MapLayersConfig;
        };
    }
}