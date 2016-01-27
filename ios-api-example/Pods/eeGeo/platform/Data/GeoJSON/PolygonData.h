// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "document.h"
#include "GeoJSONObject.h"
#include "LinearRing.h"
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace GeoJSON
        {
            class PolygonData
            {
            public:
                PolygonData(const rapidjson::Value& ringData);
                
                const size_t GetNumHoles() const;
                const LinearRing& GetHoleAt(int index) const;
                const LinearRing& GetExteriorRing() const;
                
            protected:
                const rapidjson::Value& m_coordinatesData;
                LinearRing m_exterior;
                TLinearRings m_holes;
            };
        }
    }
}