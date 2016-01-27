// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include <string>


namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            struct PlaceNameData
            {
            public:
                std::string name;
                Eegeo::dv3 positionEcef;
                std::string category;
                std::string icon;
                float priority;
                
                PlaceNameData(const std::string& name, const dv3& positionEcef, const std::string& category, const std::string& icon, float priority)
                : name(name)
                , category(category)
                , icon(icon)
                , priority(priority)
                , positionEcef(positionEcef)
                {
                        
                }
            };
        }
    }
}
