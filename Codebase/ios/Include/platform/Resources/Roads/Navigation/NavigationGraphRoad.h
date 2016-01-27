// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include "Navigation.h"
#include <vector>

// TODO: Move the road direction enum elsewhere
#include "ParsedNavGraph.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                class NavigationGraphRoad : protected Eegeo::NonCopyable
                {
                public:
                    NavigationGraphRoad(
                                        const std::vector<Eegeo::v3>::const_iterator verticesBegin,
                                        const std::vector<Eegeo::v3>::const_iterator verticesEnd,
                                        const std::vector<u16>::const_iterator connectionsToIndicesBegin,
                                        const std::vector<u16>::const_iterator connectionsToIndicesEnd,
                                        const std::vector<u16>::const_iterator connectionsFromIndicesBegin,
                                        const std::vector<u16>::const_iterator connectionsFromIndicesEnd,
                                        float halfWidth,
                                        u8 averageSpeedInKph,
                                        RoadDirection direction,
                                        u8 roughSpeedLimitInKph,
                                        FunctionalRoadClass roadClass = NotApplicable
                    );
                    
                    const std::vector<Eegeo::v3>& GetVertices() const { return m_vertices; }
                    const std::vector<int>& GetConnectionsToIndices() const { return m_connectionsToIndices; }
                    const std::vector<int>& GetConnectionsFromIndices() const { return m_connectionsFromIndices; }
                    float GetHalfWidth() const { return m_halfWidth; }
                    u8 GetAverageSpeedInKph() const { return m_averageSpeedInKph; }
                    RoadDirection GetRoadDirection() const { return m_direction; }
                    u8 GetRoughSpeedLimitInKph() const { return m_roughSpeedLimitInKph; }
                    int GetVertexCount() const { return static_cast<int>(m_vertices.size()); }
                    const FunctionalRoadClass GetFunctionalRoadClass() const { return m_functionalRoadClass; }
                    
                    bool IsConnectedAtStart(const NavigationGraphRoad& road, const NavigationGraph& navGraph) const;
                    bool IsConnectedAtEnd(const NavigationGraphRoad& road, const NavigationGraph& navGraph) const;
                    
                    bool AreConnectionsValid(const NavigationGraph& navGraph) const;
                    

                    void LinkAtStart(NavigationGraphLink* navGraphLink);
                    void LinkAtEnd(NavigationGraphLink* navGraphLink);
                    void Unlink(NavigationGraphLink* navGraphLink);
                    
                    const bool HasConnectionToCell() const { return m_connectionToCell != NULL; }
                    const bool HasConnectionFromCell() const { return m_connectionFromCell != NULL; }
                    NavigationGraphLink* GetConnectionToCell() const { return m_connectionToCell; }
                    NavigationGraphLink* GetConnectionFromCell() const { return m_connectionFromCell; }
                    const bool HasConnectionTo() { return HasConnectionToCell() || !GetConnectionsToIndices().empty(); }
                    const bool HasConnectionFrom() { return HasConnectionFromCell() || !GetConnectionsFromIndices().empty(); }
                    const bool IsActualDeadEnd(bool forwardsDirection) {
                        return (!HasConnectionTo() && forwardsDirection) ||
                            (!HasConnectionFrom() && !forwardsDirection);
                    }
                    
                    bool IsBoundaryVertexOrDeadEnd(int vertexIndex) const;
                    
                    void DisableRoad();
                    void EnableRoad();
                    void DisableVertex(int index);
                    void EnableVertex(int index);
                    bool IsVertexEnabled(int index) const;
                    bool HasDisabledVertices() const;
                    
                private:
                    bool AreConnectionsValid(const NavigationGraph& navGraph, const std::vector<int>& connectionIndices) const;
                    
                    const std::vector<Eegeo::v3> m_vertices;
                    const std::vector<int> m_connectionsToIndices;
                    const std::vector<int> m_connectionsFromIndices;
                    const float m_halfWidth;
                    const u8 m_averageSpeedInKph;
                    const RoadDirection m_direction;
                    const u8 m_roughSpeedLimitInKph;
                    const Resources::Roads::FunctionalRoadClass m_functionalRoadClass;
                    
                    std::vector<int> m_disabledVertexIndices;
                    NavigationGraphLink* m_connectionToCell;
                    NavigationGraphLink* m_connectionFromCell;
                };
            }
        }
    }
}
