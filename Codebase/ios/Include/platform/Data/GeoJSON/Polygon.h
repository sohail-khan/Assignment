// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "document.h"
#include "GeoJSONObject.h"
#include "LinearRing.h"
#include "PolygonData.h"
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace GeoJSON
        {
            class Polygon : public GeoJSONObject
            {
            public:
                Polygon(const rapidjson::Value& value);
                
                const size_t GetNumHoles() const;
                const LinearRing& GetHoleAt(int index) const;
                const LinearRing& GetExteriorRing() const;
                
            private:
                PolygonData m_polygon;
            };
        }
    }
}