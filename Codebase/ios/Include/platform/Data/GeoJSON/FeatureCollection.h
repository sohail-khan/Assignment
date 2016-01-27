//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "document.h"
#include "GeoJSONObject.h"
#include "Feature.h"

namespace Eegeo
{
    namespace Data
    {
        namespace GeoJSON
        {
            class FeatureCollection : public GeoJSONObject
            {
            public:
                FeatureCollection(const rapidjson::Value& value);
                
                int GetNumFeatures() const;
                Feature GetFeatureAt(int index) const;
            };
        }
    }
}