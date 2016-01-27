// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CityThemes.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ICityThemeStateObservable
            {
            public:
                virtual void RegisterObserver(ICityThemeStateObserver& themeStateObserver) = 0;
                virtual void UnregisterObserver(ICityThemeStateObserver& themeStateObserver) = 0;
                virtual ~ICityThemeStateObservable() {}
            };
        }
    }
}

