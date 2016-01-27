// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CityThemes.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ICityThemeChangedObservable
            {
            public:
                virtual void RegisterThemeChangedObserver(ICityThemeChangedObserver& observerToAdd) = 0;
                virtual void UnregisterThemeChangedObserver(ICityThemeChangedObserver& observerToRemove) = 0;
            };
        }
    }
}
