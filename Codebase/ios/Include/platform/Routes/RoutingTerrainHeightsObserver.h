// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "MortonKey.h"
#include "Terrain.h"
#include "TerrainHeightsCallback.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class RoutingTerrainHeightsObserver : public Eegeo::NonCopyable
        {
            Resources::Terrain::Heights::TerrainHeightRepository& m_terrainHeightRepository;
            Fitting::RouteFittingService& m_routeFittingService;

            std::vector<Eegeo::Streaming::MortonKey> m_scratchKeys;
            
            Resources::Terrain::Heights::TTerrainHeightsCallback<RoutingTerrainHeightsObserver> m_addedCallback;
            Resources::Terrain::Heights::TTerrainHeightsCallback<RoutingTerrainHeightsObserver> m_removalCallback;
            
            void HandleTerrainHeightsAdded(const Resources::Terrain::ITerrainHeightLookup& terrainHeightLookup);
            void HandleTerrainHeightsRemoved(const Resources::Terrain::ITerrainHeightLookup& terrainHeightLookup);
            
        public:
            RoutingTerrainHeightsObserver(Resources::Terrain::Heights::TerrainHeightRepository& terrainHeightRepository,
                                          Fitting::RouteFittingService& routeFittingService);
            
            ~RoutingTerrainHeightsObserver();
        };
    }
}
