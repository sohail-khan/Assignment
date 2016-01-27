// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "MortonKey.h"
#include "Geometry.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class NavGraphConformerOutputBuilder : public Eegeo::NonCopyable
                {
                public:
                    NavGraphConformerOutputBuilder(const Eegeo::Streaming::MortonKey& key,
                                                   const Route& route,
                                                   const NavGraphConforming::ConformerRouteSection& conformerRouteSection,
                                                   SelectedRoadRepository& selectedRoadRepository,
                                                   const FittingTerrainProjector& fittingTerrainProjector,
                                                   const NavGraphConformerConfig& config);
                    
                    virtual ~NavGraphConformerOutputBuilder();
                    
                           
                    void BuildOutput(const std::vector<const CandidateSet*>& candidates,
                                     const std::vector<ConformerSolution>& rangeSolutions,
                                     std::vector<FittedRouteSection>& out_fittedRouteSections);

                private:
                    const Eegeo::Streaming::MortonKey m_key;
                    const Route& m_route;
                    const FittingTerrainProjector& m_fittingTerrainProjector;
                    const NavGraphConformerConfig& m_config;
                    
                    Geometry::Point3Spline* m_inputRouteSectionSpline;
                    int m_routeSectionSplineStartIndex;
                    
                    
                    SelectedRoadRepository& m_selectedRoadRepository;
                    
                    void BuildFittedRouteSectionsFromFittedRanges(const std::vector<FittedRangeForRoad>& fittedRanges, std::vector<FittedRouteSection>& out_fittedRouteSections);
                    
                    void BuildFittedRouteSection(const FittedRangeForRoad& fittedRange, std::vector<LocalRouteVertex>& out_localVertices);
                    
                    void BuildUnfittedRouteSection(const FittedRangeForRoad& fittedRange, std::vector<LocalRouteVertex>& out_localVertices);
                    
                    bool CanExtendPreviousFittedRange(const FittedRangeForRoad* fittedRange, const FittedRangeForRoad* prevFittedRange) const;

                    FittedRouteSection CreateFittedRouteSection(const std::vector<LocalRouteVertex>& localVertices);
                    
                    void AssignRouteParams(const std::vector<LocalRouteVertex>& localVertices, std::vector<LocalRouteVertex>& out_localVerticesWithRouteParam) const;
                  
                    void LogFittedRanges(const std::vector<FittedRangeForRoad>& fittedRanges);

                    void ValidateOutput(const std::vector<FittedRouteSection>& fittedRouteSections);
                    
                    double GetRouteParamAtClosestPointOnInputRoute(const v3& position) const;
                };
            }
        }
    }
}
