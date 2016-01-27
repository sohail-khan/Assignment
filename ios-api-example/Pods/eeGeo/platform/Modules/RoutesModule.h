// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Rendering.h"
#include "Streaming.h"
#include "Resources.h"
#include "Lighting.h"
#include "Terrain.h"
#include "Navigation.h"
#include "Modules.h"

#include "RouteRepository.h"
#include "FittedRouteRepository.h"
#include "RouteViewRepository.h"
#include "RouteClippingService.h"
#include "RouteSimulationViewRepository.h"
#include "RouteSimulationSessionRepository.h"

namespace Eegeo
{
    namespace Modules
    {
        class RoutesModule : protected Eegeo::NonCopyable
        {
        public:
            static RoutesModule* Create(
                    Modules::Core::CoreModule& coreModule,
                    Modules::Map::MapModule& mapModule);
            
            RoutesModule(
                         Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                         Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                         Rendering::GlBufferPool& glBufferPool,
                         Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                         Rendering::Materials::NullMaterialFactory& nullMaterialFactory,
                         Rendering::RenderableFilters& renderableFilters,
                         Eegeo::Lighting::GlobalFogging& fogging,
                         Streaming::SceneGraphCellRepository& sceneGraphCellRepository,
                         const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                         Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                         Eegeo::Resources::Terrain::Heights::TerrainHeightRepository& terrainHeightRepository,
                         Eegeo::Resources::Roads::Navigation::NavigationGraphRepository& roadNavGraphRepository,
                         Eegeo::Resources::Roads::Navigation::NavigationGraphRepository& railNavGraphRepository,
                         Rendering::Filters::SceneModelRenderableFilter& sceneModelRenderableFilter
                         );
            ~RoutesModule();
            
            Routes::RouteService& GetRouteService() const;
            Routes::RouteFactory& GetRouteFactory() const;
            Routes::Simulation::RouteSimulationService& GetRouteSimulationService() const;
            Routes::Simulation::RouteSimulationSessionRepository& GetRouteSimulationSessionRepository();
            Routes::Simulation::View::RouteSimulationViewService& GetRouteSimulationViewService() const;
            Routes::RouteRepository& GetRouteRepository();
            Routes::View::RouteViewRepository& GetRouteViewRepository();
            Routes::Fitting::FittedRouteFactory& GetFittedRouteFactory() const;
            Routes::Fitting::FittedRouteRepository& GetFittedRouteRepository();
            Routes::Fitting::RouteFittingService& GetRouteFittingService() const;
            Routes::View::RouteViewRenderer& GetRouteViewRenderer() const;
            
            void EarlyUpdate(float dt);
            void Update(float dt);
            
        private:
            Rendering::RenderableFilters& m_renderableFilters;
            
            Routes::RouteRepository m_routeRepository;
            Routes::RouteStyleRepository* m_pRouteStyleRepository;
            Routes::View::RouteViewFactoryRepository* m_pRouteViewFactoryRepository;
            Routes::StyleMappingRouteObserver *m_pStyleMappingRouteObserver;
            Routes::View::ViewFactoryMappingRouteObserver *m_pViewFactoryMappingRouteObserver;
            Routes::Fitting::FittedRouteRepository m_fittedRouteRepository;
            Routes::Fitting::FittedRouteFactory* m_pFittedRouteFactory;
            Routes::Fitting::RouteObserver* m_pRouteFittingRouteObserver;
            Routes::View::RouteViewRepository m_routeViewRepository;
            Routes::View::RouteViewStyleObserver* m_pRouteViewStyleObserver;
            Routes::Fitting::RouteFittingService* m_pRouteFittingService;
            Routes::Fitting::NavGraphFittingInfoService* m_pNavGraphFittingInfoService;
            Routes::Fitting::NavGraphFittingInfoRepository* m_pRoadNavGraphFittingInfoRepository;
            Routes::Fitting::NavGraphFittingInfoRepository* m_pRailNavGraphFittingInfoRepository;
            Routes::Clipping::RouteClippingService m_routeClippingService;
            Routes::RouteFactory* m_pRouteFactory;
            Rendering::VertexLayouts::VertexLayout* m_pRouteRenderVertexLayout;
            Routes::View::RouteViewMeshFactory* m_pRouteViewMeshFactory;
            Routes::View::IRouteViewFactory* m_pDefaultRouteViewFactory;
            Routes::View::RouteViewShader* m_pRouteViewShader;
            Routes::View::RouteViewMaterial* m_pRouteViewMaterial;
            Routes::RouteService* m_pRouteService;
            Routes::View::RouteViewService* m_pRouteViewService;
            Routes::RoutingNavigationGraphObserver* m_pRoutingNavigationGraphObserver;
            Routes::RoutingTerrainHeightsObserver* m_pRoutingTerrainHeightsObserver;
            Routes::RoutingSceneGraphObserver* m_pRoutingSceneGraphObserver;
            Routes::View::RouteViewFittedRouteObserver* m_pRouteViewFittedRouteObserver;
            Routes::View::RouteViewRenderer* m_pRouteViewRenderer;
            Routes::Simulation::RouteSamplerFactory* m_pRouteSamplerFactory;
            Routes::Simulation::RouteSimulationSessionFactory* m_pRouteSimulationSessionFactory;
            Routes::Simulation::RouteSimulationService* m_pRouteSimulationService;
            Routes::Simulation::View::RouteSimulationViewFactory* m_pRouteSimulationViewFactory;
            Eegeo::Rendering::Materials::NullMaterial* m_pRouteSimulationViewNullMaterial;
            Routes::Simulation::View::RouteSimulationViewRepository m_routeSimulationViewRepository;
            Routes::Simulation::View::RouteSimulationViewService* m_pRouteSimulationViewService;
            Routes::Simulation::RouteSimulationSessionRepository m_routeSimulationSessionRepository;
            Routes::Simulation::RouteSimulationSessionFittedRouteObserver* m_pRouteSimulationSessionFittedRouteObserver;
            Routes::Simulation::RouteSimulationRouteObserver* m_pRouteSimulationRouteObserver;
        };
    }
}
