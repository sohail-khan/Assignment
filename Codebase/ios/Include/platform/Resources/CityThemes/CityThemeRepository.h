// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ICityThemeRepository.h"
#include "Types.h"
#include "CityThemes.h"
#include "CityThemeData.h"
#include "Space.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemeRepository : public ICityThemeRepository, protected Eegeo::NonCopyable
            {
            private:
                std::vector<CityThemeData*> m_themes;
               
            public:
                CityThemeRepository();
                ~CityThemeRepository();
                
                void AddTheme(CityThemeData* pTheme);
                const CityThemeData* GetThemeDataByName(const std::string& themeName) const;
                const CityThemeData* GetThemeDataByLocation(const Space::LatLong& latLong) const;
                const CityThemeData* GetThemeDataByLocationAndNameContaining(const Space::LatLong& latLong, const std::string& nameContains) const;
            

                int GetNumberOfThemes() const;
                const CityThemeData& GetCityThemeAt(int index) const;
            };
        }
    }
}
