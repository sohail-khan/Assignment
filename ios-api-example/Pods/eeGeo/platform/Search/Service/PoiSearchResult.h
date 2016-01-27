// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LatLongAltitude.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            struct PoiSearchEntry
            {
                PoiSearchEntry():location(0,0){}
                
                Space::LatLong location;
                std::string name;
                std::string placeId;
                std::string category;
                std::string vicinity;
            };
            
            struct PoiSearchResult
            {
                bool success;
                std::vector<PoiSearchEntry> entries;
            };
        }
    }
}