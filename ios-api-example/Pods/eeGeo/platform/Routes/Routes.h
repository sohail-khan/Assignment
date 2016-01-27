// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Routes
    {
        class Route;
        class IRouteCallback;
        class RouteRepository;
        class RouteFactory;
        class RouteService;
        class RouteVertex;
        class LocalRouteVertex;
        class RouteBuilder;
        class RoutingNavigationGraphObserver;
        class RoutingTerrainHeightsObserver;
        class RoutingSceneGraphObserver;
        class RouteVertexDebugVisualiser;
        class RouteStyleRepository;
        class StyleMappingRouteObserver;
        class IRouteCreator;
        
        namespace Clipping
        {
            struct ClippedRouteVertex;
            struct ClippedRouteSection;
            class RouteClippingService;
            class ClippedRoute;
        }
        
        namespace Fitting
        {
            struct FittedRoute;
            struct FittedRouteSection;

            class FittedRouteRepository;
            class IFittedRouteCallback;
            class NavGraphRoadFittingInfo;
            class NavGraphFittingInfoForKey;
            class NavGraphFittingInfoRepository;
            class NavGraphFittingInfoService;
            class RouteFittingService;
            class FittedRouteFactory;
            class NavGraphRoadFittingInfo;
            class FittingTerrainProjector;
            class NavGraphDebugAnnotation;
            class RouteObserver;
            
            namespace NavGraphConforming
            {
                class CandidateSet;
                class CandidateSetGenerator;
                class NavGraphConformer;
                class NavGraphConformerCandidateGenerator;
                class NavGraphConformerOutputBuilder;
                class RangeSolver;
                class NavGraphConformerSolver;
                class SolverNodeAllocator;
                struct Candidate;
                struct SolverNode;
                struct ConformerSolution;
                struct SolverConfig;
                struct NavGraphConformerConfig;
                struct SolverRange;
                struct FittedRangeForRoad;
                struct SelectedRoad;
                class SelectedRoadRepository;
                class SolverRangeBuilder;
                struct ConformerRouteSection;
            }
        }
        
        namespace Style
        {
            namespace Thickness
            {
                class IRouteThicknessPolicy;
                class IdentityRouteThicknessPolicy;
                class IRouteThicknessPolicy;
                class LinearAltitudeBasedRouteThicknessPolicy;
            }
            
            
            class RouteStyle;
        }
        
        namespace Simulation
        {
            class RouteSimulationService;
            class RouteSimulationSession;
            class RouteSimulationSessionFactory;
            class RouteSimulationSessionRepository;
            class RouteSimulationSessionFittedRouteObserver;
            class IRouteSimulationSessionObserver;
            class RouteSimulationRouteObserver;
            class IRouteSimulationSessionCallback;
            class RouteSample;
            class RouteSampler;
            class RouteSamplerFactory;
            
            namespace Camera
            {
                class RouteSimulationGlobeCameraController;
                class RouteSimulationGlobeCameraControllerFactory;
                struct RouteSimulationGlobeCameraControllerConfig;
            }
            
            namespace View
            {
                class RouteSimulationModelBinding;
                class RouteSimulationViewService;
                class RouteSimulationViewRepository;
                class RouteSimulationViewFactory;
            }
        }
        
        namespace View
        {
            class RouteView;
            class IRouteViewFactory;
            class RouteViewFactory;
            class RouteViewShader;
            class RouteViewRepository;
            class RouteViewFactoryRepository;
            class ViewFactoryMappingRouteObserver;
            class RouteViewService;
            class RouteViewRenderer;
            class RouteViewRenderable;
            class RouteViewMaterial;
            class RouteViewMeshFactory;
            class RouteViewStyleObserver;
            class IRouteViewStyleCallback;
            class RouteViewFittedRouteObserver;
            class RouteViewSegment;
            class RouteViewGeometryFactory;
            struct RouteRenderVertex;
            struct RouteVert;
        }
    }
}
