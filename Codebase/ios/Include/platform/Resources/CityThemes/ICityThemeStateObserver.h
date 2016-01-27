// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CityThemes.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ICityThemeStateObserver
            {
            public:
                virtual void OnThemeStateChanged(const Eegeo::Resources::CityThemes::CityThemeState& state) = 0;
                virtual ~ICityThemeStateObserver() {};
            };
        }
    }
}

