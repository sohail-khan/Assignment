// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Space.h"
#include "Streaming.h"
#include "Navigation.h"
#include "DoublePlane.h"
#include "VectorMathDecl.h"
#include "Geometry.h"
#include "CubeMapCellInfo.h"
#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class NavGraphFittingInfoForKey
            {
            public:
                NavGraphFittingInfoForKey(const Space::CubeMap::CubeMapCellInfo& cellInfo,
                                          const std::vector<const NavGraphRoadFittingInfo*>& roadSplines,
                                          const std::vector<Geometry::DoublePlane>& cellBoundaryPlanes);
            
                virtual ~NavGraphFittingInfoForKey();
                
                const Streaming::MortonKey& Key() const { return m_cellInfo.GetKey(); }
                const Space::CubeMap::CubeMapCellInfo& CellInfo() const { return m_cellInfo; }
                
                const std::vector<const NavGraphRoadFittingInfo*>& Values() const  { return m_roadSplines; }
                
                bool IntersectsCell(const Geometry::SingleSphere& sphere) const;
                float DistanceToCellBoundary(const v3& point) const;
                
                static float DistanceToCellBoundary(const v3& point, const dv3& cellOrigin, const std::vector<Geometry::DoublePlane>& cellBoundaryPlanes);
                
                static NavGraphFittingInfoForKey* Create(const Resources::Roads::Navigation::NavigationGraph& navGraph);
                
                
            private:
                const Space::CubeMap::CubeMapCellInfo m_cellInfo;
                
                std::vector<const NavGraphRoadFittingInfo*> m_roadSplines;
                
                std::vector<Geometry::DoublePlane> m_cellBoundaryPlanes;
                
                static void CreateRoadSplines(const Resources::Roads::Navigation::NavigationGraph& navGraph, std::vector<const NavGraphRoadFittingInfo*>& out_roadSplines);
            };
        }
    }
}
