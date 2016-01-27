// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Traffic.h"

namespace Eegeo
{
    namespace Traffic
    {
        namespace Themes
        {
            class ITrafficThemeModelObserver
            {
            public:
                virtual void OnThemeChanged (const TrafficThemeModel& themeModel) = 0;
                virtual void OnThemeStateChanged (const TrafficThemeModel& themeModel) = 0;
                virtual ~ITrafficThemeModelObserver() {};
            };
        }
    }
}
