// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            struct PoiInfoResult
            {
                std::string name;
                std::string address;
                std::string phone;
                std::string webUrl;
                
                bool success;
            };
        }
    }
}
