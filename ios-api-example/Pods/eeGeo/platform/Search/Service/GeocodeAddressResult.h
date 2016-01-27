// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "LatLongAltitude.h"

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            struct GeocodeAddressResult
            {
                GeocodeAddressResult():location(0,0){}
                
                bool success;
                Space::LatLong location;
                std::string name;
            };
        }
    }
}
