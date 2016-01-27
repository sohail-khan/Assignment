// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "document.h"
#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace GeoJSON
        {
            typedef std::vector<Eegeo::dv2> TLinearRing;

            class LinearRing
            {
            public:
                LinearRing(const rapidjson::Value& value);
                
                const TLinearRing& GetRing() const;
            private:
                mutable bool m_parsed;
                mutable TLinearRing m_ring;
                const rapidjson::Value* m_pValue;
            };
            
            typedef std::vector<LinearRing> TLinearRings;
        }
    }
}