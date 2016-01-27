// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LatLongAltitude.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            struct AddressSearchEntry
            {
                AddressSearchEntry():location(0,0){}
                
                Space::LatLong location;
                std::string name;
            };
            
            struct AddressSearchResult
            {
                bool success;
                std::vector<AddressSearchEntry> entries;
            };
        }
    }
}