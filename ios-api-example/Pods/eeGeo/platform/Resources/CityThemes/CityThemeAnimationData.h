// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LatLongAltitude.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemeAnimationData
            {
            public:
                std::string Name;
                std::string Url;
                Space::LatLongAltitude Location;
                float FrameRateScale;
                
                CityThemeAnimationData();
            };
        }
    }
}