// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "NavGraphConformerConfig.h"
#include "Terrain.h"
#include "Streaming.h"
#include "Navigation.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            struct FittedRouteFactoryConfig
            {
                NavGraphConforming::NavGraphConformerConfig conformerConfig;
            };
            
            class FittedRouteFactory
            {
            private:
                const Fitting::NavGraphFittingInfoRepository& m_roadNavGraphSplineRepository;
                const Fitting::NavGraphFittingInfoRepository& m_railNavGraphSplineRepository;
                const Streaming::SceneGraphCellRepository& m_sceneGraphCellRepository;
                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                Eegeo::Routes::Fitting::NavGraphDebugAnnotation* m_navGraphDebugAnnotation;                
                
                bool m_fittingToNavgraphEnabled;
                
                FittedRouteFactoryConfig m_config;
                
                void UpdateDebugNavGraphAnnotation(const Streaming::MortonKey& key);
            public:
                
                FittedRouteFactory(const Fitting::NavGraphFittingInfoRepository& roadNavGraphSplineRepository,
                                   const Fitting::NavGraphFittingInfoRepository& railNavGraphSplineRepository,
                                   const Streaming::SceneGraphCellRepository& sceneGraphCellRepository,
                                   const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                   const FittedRouteFactoryConfig& config);
                
                FittedRoute* CreateFittedRoute(const Route* pRoute, const Eegeo::Streaming::MortonKey& key);
                
                FittedRoute* CreateUnfittedRoute(const Route* pRoute, const Eegeo::Streaming::MortonKey& key);

                bool FittingToNavgraphEnabled() const;
                
                void ToggleFittingToNavgraph();
                
                bool IsUnfittedSectionHighlightEnabled() const;
                
                void ToggleHighlightUnfittedSections();
                
                FittedRouteFactoryConfig GetConfig() const { return m_config; }
                void SetConfig(const FittedRouteFactoryConfig& config) { m_config = config; }
                
                void SetNavGraphDebugVisualiser(Eegeo::Routes::Fitting::NavGraphDebugAnnotation* visualiser) { m_navGraphDebugAnnotation = visualiser; }
                
                static FittedRouteFactoryConfig DefaultConfig();
            };
        }
    }
}