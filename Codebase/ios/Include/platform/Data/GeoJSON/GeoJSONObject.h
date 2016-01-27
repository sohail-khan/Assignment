// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "document.h"
#include "GeoJSONTypes.h"
#include "GeoJSON.h"

namespace Eegeo
{
    namespace Data
    {
        namespace GeoJSON
        {
            class GeoJSONObject
            {
            public:
                GeoJSONObject(const rapidjson::Value& value);
                
                const Types GetType() const { return m_type; }

                Polygon AsPolygon() const;
                MultiPolygon AsMultiPolygon() const;
                Feature AsFeature() const;
                FeatureCollection AsFeatureCollection() const;
                
            protected:
                const rapidjson::Value& m_value;
                const Types m_type;
            };
        }
    }
}
