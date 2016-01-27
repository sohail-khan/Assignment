// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "CityThemes.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemeJsonParser : protected Eegeo::NonCopyable
            {
            public:
                bool ParseThemes(const std::string& themeJson,
                                 std::vector<CityThemeData*>& themes);
                
                bool ParseEmbeddedThemes(const std::string& themeJson,
                                         const std::string& localTexturePath,
                                         std::vector<CityThemeData*>& themes);
                
            private:
                bool ParseThemeJson(const std::string& themeJson,
                                    const bool useLocalTextureFilePaths,
                                    const std::string& localTexturePath,
                                    std::vector<CityThemeData*>& themes);
            };
        }
    }
}