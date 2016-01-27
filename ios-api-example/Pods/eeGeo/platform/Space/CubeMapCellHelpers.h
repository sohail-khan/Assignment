// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Space.h"
#include "Streaming.h"
#include "Geometry.h"
#include "VectorMathDecl.h"
#include <vector>

namespace Eegeo
{
    namespace Space
    {
        namespace CubeMapCellHelpers
        {
            void CalculateCellBoundaryPlanes(const CubeMap::CubeMapCellInfo& cellInfo, std::vector<Geometry::DoublePlane>& out_planes);
            
            void CalculateCellSplitPlanes(const Streaming::MortonKey& key, Geometry::DoublePlane& splitPlaneRightPositive, Geometry::DoublePlane& out_splitPlaneTopPositive);
            
            void CalculateLatLongBounds(const CubeMap::CubeMapCellInfo& cellInfo, Space::LatLong& out_southWestLatLong, Space::LatLong& out_northEastLatLong);
    
            bool LineSegmentIntersectsWithCubeFaceEdge(const dv3& ecefPointA, const dv3& ecefPointB, const int cubeFaceIndex, double& out_closestIntersectionParam);        
        };
    }
}
