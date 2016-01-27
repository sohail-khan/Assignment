// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CityThemes.h"
#include "Space.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ICityThemeRepository
            {
            public:
                virtual ~ICityThemeRepository() {}

                virtual const CityThemeData* GetThemeDataByName(const std::string& themeName) const = 0;
                
                virtual const CityThemeData* GetThemeDataByLocation(const Space::LatLong& latLong) const = 0;
                
                virtual const CityThemeData* GetThemeDataByLocationAndNameContaining(const Space::LatLong& latLong, const std::string& nameContains) const = 0;
                
                virtual int GetNumberOfThemes() const = 0;

                virtual const CityThemeData& GetCityThemeAt(int index) const = 0;
            };
        }
    }
}
