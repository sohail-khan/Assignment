// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "MortonKey.h"
#include "NavGraphConformerConfig.h"
#include "SelectedRoadRepository.h"
#include "NavGraphConformerConfig.h"
#include "CubeMapCellInfo.h"
#include "Streaming.h"

#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class NavGraphConformer : public Eegeo::NonCopyable
                {
                public:
                    NavGraphConformer(const NavGraphConformerConfig& config,
                                      const Route& route,
                                      const Eegeo::Streaming::MortonKey& key,
                                      const NavGraphFittingInfoRepository& roadNavGraphFittingInfoRepository,
                                      const NavGraphFittingInfoRepository& railNavGraphFittingInfoRepository,
                                      const Streaming::SceneGraphCellRepository& sceneGraphCellRepository,
                                      const FittingTerrainProjector& fittingTerrainProjector);


                
                    virtual ~NavGraphConformer();
                    
                    virtual void GenerateInputForKeyAndNeighbours(std::vector<NavGraphConforming::ConformerRouteSection>& out_mergedRouteSections);
                
                    virtual void GenerateInputForKeyOnly(std::vector<NavGraphConforming::ConformerRouteSection>& out_mergedRouteSections);
                
                    virtual FittedRoute* CreateFittedRoute(const std::vector<NavGraphConforming::ConformerRouteSection>& mergedRouteSections);

                private:
                
                    const Route& m_route;
                    const Eegeo::Streaming::MortonKey m_key;
                    const Eegeo::Space::CubeMap::CubeMapCellInfo m_cellInfo;
                    const NavGraphFittingInfoRepository& m_roadNavGraphFittingInfoRepository;
                    const NavGraphFittingInfoRepository& m_railNavGraphFittingInfoRepository;
                    const Streaming::SceneGraphCellRepository& m_sceneGraphCellRepository;
                    const FittingTerrainProjector& m_fittingTerrainProjector;
                    
                    const NavGraphConformerConfig m_config;
                    
                    std::vector<Streaming::MortonKey> m_keyAndAdjacents;
                    SelectedRoadRepository m_selectedRoadRepository;

                    void GenerateClippedRouteSectionsForKeyAndNeighbours(std::vector<Clipping::ClippedRouteSection>& out_clippedRouteSections);

                    bool ConformRouteSections(const NavGraphConforming::ConformerRouteSection& conformerRouteSection,
                                              const std::vector<LocalRouteVertex>& inputLocalRouteVertices,
                                                std::vector<FittedRouteSection>& out_conformedSections);
                    
                    bool TryBuildFittedRouteSections(const std::vector<NavGraphConforming::ConformerRouteSection>& mergedRouteSections,
                                                     std::vector<FittedRouteSection>& out_fittedRouteSections);
                    
                    
                    bool TryBuildFittedRouteSections(const NavGraphConforming::ConformerRouteSection& conformerRouteSection,
                                                  std::vector<FittedRouteSection>& out_fittedRouteSections);
                };
            }
        }
    }
}
