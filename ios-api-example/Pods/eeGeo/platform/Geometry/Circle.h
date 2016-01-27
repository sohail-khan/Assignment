//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include <vector>
#include "LatLongAltitude.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Geometry
    {
        void GenerateLatLongCircle(const Space::LatLongAltitude& centre,
                                   float radiusInMetres,
                                   const int segments,
                                   std::vector<Space::LatLongAltitude>& out_circle);
        
        void GenerateLatLongCircle(const Eegeo::dv3& centreEcef,
                                   float radiusInMetres,
                                   const int segments,
                                   std::vector<dv3>& out_circleEcef);
    }
}