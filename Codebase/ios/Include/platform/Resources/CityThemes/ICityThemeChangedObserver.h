// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CityThemes.h"

namespace Eegeo
{
    
    namespace Resources
    {
        namespace CityThemes
        {
            class ICityThemeChangedObserver
            {
            public:

                virtual void OnThemeRequested(const CityThemeData& newTheme) = 0;
                virtual void OnThemeChanged(const CityThemeData& newTheme) = 0;
                
                virtual ~ICityThemeChangedObserver() {};

            };
        }
        
    }
}