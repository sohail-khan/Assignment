// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Space.h"
#include "VectorMathDecl.h"
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace Geofencing
        {
            void TriangulateGeofence(
                    const std::vector<Space::LatLongAltitude>& exteriorRingVertices,
                    const std::vector<std::vector<Space::LatLongAltitude> >& interiorRings,
                    const float altitudeOffset,
                    dv3& out_ecefCellCenter,
                    std::vector<dv3>& out_ecefTriangleVertices,
                    std::vector<dv3>& out_ecefExteriorRingVertices);
        }
    }
}

