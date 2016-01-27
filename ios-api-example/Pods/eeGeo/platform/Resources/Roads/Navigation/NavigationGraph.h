// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuiltResourceWithKey.h"
#include "Types.h"
#include "Navigation.h"
#include "Space.h"
#include "VectorMath.h"
#include "CubeMapCellInfo.h"
#include <vector>
#include <algorithm>

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                class NavigationGraph : public BuiltResourceWithKey, protected Eegeo::NonCopyable
                {
                public:
                    typedef std::vector<NavigationGraphRoad*> TRoadsVector;
                    
                    NavigationGraph(const Eegeo::Space::CubeMap::CubeMapCellInfo& cellInfo,
                                    TRoadsVector roads,
                                    const std::vector<u16>::const_iterator roadIndicesJoiningCellBegin,
                                    const std::vector<u16>::const_iterator roadIndicesJoiningCellEnd,
                                    const std::vector<u16>::const_iterator roadIndicesLeavingCellBegin,
                                    const std::vector<u16>::const_iterator roadIndicesLeavingCellEnd,
                                    NavigationGraphRepository* const navigationGraphRepository,
                                    size_t totalVerticesInNavigationGraph);
                    
                    NavigationGraph(const Eegeo::Space::CubeMap::CubeMapCellInfo& cellInfo,
                                    NavigationGraphRepository* const navigationGraphRepository);
                    
                    virtual ~NavigationGraph();

                    const Eegeo::Space::CubeMap::CubeMapCellInfo& GetCellInfo() const { return m_cellInfo; }
                    size_t GetTotalVerticesInNavigationGraph() const { return m_totalVerticesInNavigationGraph; }
                    
                    const Eegeo::v3& GetUpECEF() const { return m_upECEF; }
                    const TRoadsVector& GetRoads() const { return m_roads; }
                    const std::vector<u16> GetRoadIndicesJoiningCell() const { return m_roadIndicesJoiningCell; }
                    const std::vector<u16> GetRoadIndicesLeavingCell() const { return m_roadIndicesLeavingCell; }
                    const TRoadsVector& GetRoadsWithCellConnections() const { return m_roadsWithCellConnections; }
                    void ClearRoadsWithCellConnections() { m_roadsWithCellConnections.clear(); }
                    
                    void Unload();
                    void AddedToSceneGraph();
                    void RemovedFromSceneGraph();

                    void RegisterRoadWithCellConnection(NavigationGraphRoad* road);
                    bool OwnsRoad(NavigationGraphRoad* road) const { return std::find(m_roads.begin(), m_roads.end(), road) != m_roads.end(); }

                private:
                    bool IsValid() const;
                    bool AreConnectionsValid() const;
                    
                    TRoadsVector m_roads;
                    TRoadsVector m_roadsWithCellConnections;
                    std::vector<u16> m_roadIndicesLeavingCell;
                    std::vector<u16> m_roadIndicesJoiningCell;
                    Eegeo::Space::CubeMap::CubeMapCellInfo m_cellInfo;
                    Eegeo::v3 m_upECEF;
                    NavigationGraphRepository* m_navigationGraphRepository;
                    size_t m_totalVerticesInNavigationGraph;
                };
            }
        }
    }
}
