//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "document.h"
#include "GeoJSONObject.h"
#include "PolygonData.h"

namespace Eegeo
{
    namespace Data
    {
        namespace GeoJSON
        {
            class MultiPolygon : public GeoJSONObject
            {
            public:
                MultiPolygon(const rapidjson::Value& value);
                
                int GetNumPolygons() const;
                PolygonData GetPolygonAt(int index) const;
            };
        }
    }
}