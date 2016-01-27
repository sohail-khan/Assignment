// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "VectorMath.h"
#include "MortonKey.h"
#include "LatLongAltitude.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        struct BuildingFootprint
        {
            std::string BuildingPartId;
            std::string BuildingGroupId;
            dv3 CentroidSeaLevelEcef;
            dv3 LocalEcefOrigin;
            float BoundingRadius;
            float OutlineArea;
            bool IsOnGround;
            float BaselineAltitude;
            float BottomAltitude;
            float Height;
            float IslandTopAltitude;
            std::vector<v3> OutlinePointsLocalEcef;
            std::vector<u16> TriangulationIndices;
            
            BuildingFootprint();
        };
    }
}