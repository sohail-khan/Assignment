// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "Space.h"
#include "Geometry.h"
#include "VectorMathDecl.h"
#include "VectorMath.h"
#include "Bounds.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class CandidateSetGenerator
                {
                public:
                    CandidateSetGenerator(const std::vector<LocalRouteVertex>& inputLocalRouteVertices,
                                          const std::vector<int>& clipVertexIndices,
                                          const Space::CubeMap::CubeMapCellInfo& cellInfo,
                                          const std::vector<const NavGraphFittingInfoForKey*>& roadFittingInfos,
                                          const std::vector<const NavGraphFittingInfoForKey*>& railFittingInfos,
                                          const Geometry::Point3Spline& routeSectionSpline,
                                          const float maxRadius,
                                          bool debugLog);

                    void CreateCandidateSets(std::vector<const CandidateSet*>& out_candidateSets, bool& out_anyCandidatesFound);
                    
                private:
                    CandidateSet* CreateCandidateSet(int srcVertexIndex);
        
                    void CreateCandidatesForVertex(
                                                  const v3& lineSegmentStart,
                                                  const v3& lineSegmentEnd,
                                                  const std::vector<const NavGraphRoadFittingInfo*>& fittingInfos,
                                                  std::vector<Candidate*>& out_candidates,
                                                  int& out_uniqueRoadCount
                                                  );
                    
                    void CreateCandidatesForRoad(const v3& lineSegmentStartInFittingInfo,
                                                 const v3& lineSegmentEndInFittingInfo,
                                                 const NavGraphRoadFittingInfo& roadInfo,
                                                 const v3& translationToFittingInfoCell,
                                                 std::vector<Candidate*>& out_candidates);
                    
                    bool IsRoadPotentiallyClipped(const NavGraphRoadFittingInfo& roadInfo) const;
                    
                    bool IsRoadEncapsulatedByInflatedRoute(
                                                  const Geometry::Point3Spline& roadSpline,
                                                  const v3& translationToCentralCell) const;
                    
                    bool IsRoadPotentiallyIntersectingRoute(const Geometry::Point3Spline& roadSpline,
                                                            const v3& translationToFittingInfoCell,
                                                            std::vector<v3>::const_iterator routePointsStart,
                                                            std::vector<v3>::const_iterator routePointsEnd) const;
                    
                    void FindRoadsPotentiallyIntersectingRoute(const std::vector<const NavGraphFittingInfoForKey*>& fittingInfos,
                                                               std::vector<const NavGraphRoadFittingInfo*>& out_roadFittingInfos) const;
                    
                    void FindRoadsEncapsulatedByInflatedRoute(const std::vector<const NavGraphRoadFittingInfo*>& roadsPotentiallyIntersectingRoute,
                                                                        std::vector<const NavGraphRoadFittingInfo*>& out_roadsEncapsulatedByInflatedRoute,
                                                                        std::vector<const NavGraphRoadFittingInfo*>& out_remainder) const;
                    
                    void FindRoadsPotentiallyClipped(const std::vector<const NavGraphRoadFittingInfo*>& roads,
                                                     std::vector<const NavGraphRoadFittingInfo*>& out_roadsPotentiallyClipped) const;
                    
                    void FindCandidateRoads(const std::vector<const NavGraphFittingInfoForKey*>& fittingInfos,
                                                   std::vector<const NavGraphRoadFittingInfo*>& out_roadFittingInfos) const;
                    
                    
                    const std::vector<LocalRouteVertex>& m_inputLocalRouteVertices;
                    const std::vector<int>& m_clipVertexIndices;
                    const Space::CubeMap::CubeMapCellInfo& m_cellInfo;

                    std::vector<const NavGraphRoadFittingInfo*> m_roadCandidateFittingInfos;
                    std::vector<const NavGraphRoadFittingInfo*> m_railCandidateFittingInfos;
                    
                    const Geometry::Point3Spline& m_routeSectionSpline;
                    const float m_maxRadius;
                    Eegeo::Geometry::Bounds3D m_inflatedRouteSectionBounds;
                    bool m_debugLog;
                };
            }
        }
    }
}
