//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "document.h"
#include "GeoJSONObject.h"

namespace Eegeo
{
    namespace Data
    {
        namespace GeoJSON
        {
            class Feature : public GeoJSONObject
            {
            public:
                Feature(const rapidjson::Value& value);
                
                GeoJSONObject GetGeometry() const;
            };
        }
    }
}