// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include <vector>
#include "EegeoSDK.h"
#include "Timer.h"
#include "PlatformConfig.h"
#include "WebLoadRequestCompletionCallback.h"
#include "EnvironmentCharacterSet.h"
#include "LoadingScreen.h"
#include "DefaultWorkPool.h"
#include "Tasks.h"
#include "IJpegLoader.h"
#include "Modules.h"
#include "IPlatformAbstractionModule.h"
#include "CoreModule.h"
#include "MapModule.h"
#include "TrafficModule.h"
#include "RoutesModule.h"
#include "RenderingModule.h"
#include "LightingModule.h"
#include "FontsModule.h"
#include "TerrainModelModule.h"
#include "TerrainPresentationModule.h"
#include "TerrainStreamingModule.h"
#include "TransportModelModule.h"
#include "TransportPresentationModule.h"
#include "TransportStreamingModule.h"
#include "BuildingModelModule.h"
#include "BuildingPresentationModule.h"
#include "BuildingStreamingModule.h"
#include "PlaceNamesModelModule.h"
#include "PlaceNamesPresentationModule.h"
#include "PlaceNamesStreamingModule.h"
#include "ShadowModelModule.h"
#include "ShadowPresentationModule.h"
#include "StreamingModule.h"
#include "DebugRenderingModule.h"
#include "AsyncLoadersModule.h"
#include "EnvironmentMaterialModule.h"
#include "DataModule.h"
#include "Web.h"

#include "WorldStateManager.h"
#include "AsyncLoadersModule.h"
#include "FrameTimer.h"
#include "FrameTimerVisualiser.h"
#include "Profiler.h"
#include "ProfileVisualiser.h"
#include "Rendering.h"
#include "EegeoUpdateParameters.h"
#include "EegeoDrawParameters.h"


#define EEGEO_PLATFORM_VERSION_NUMBER "1837"
#define EEGEO_PLATFORM_VERSION_HASH "2c454c16323ae70dd92c5991cb6bb07c7ff7fd99"

//! Contains Eegeo Apps on Maps SDK for mobile
namespace Eegeo
{
    class EegeoWorld
    {
    private:

        WorldStates::WorldStateManager* m_pWorldStateManager;

        Debug::FrameTimer* m_pFrameTimer;
        Debug::FrameTimerVisualiser* m_pFrameTimerVisualiser;

        Debug::Profile::Profiler* m_pProfiler;
        Debug::Profile::ProfileVisualiser* m_pProfileVisualiser;
        
        Concurrency::Tasks::DefaultWorkPool* m_pWorkPool;
        
        Web::ApiTokenValidator* m_pApiTokenValidator;
        
        Modules::Core::CoreModule* m_pCoreModule;
        Modules::Map::MapModule* m_pMapModule;
        Modules::Data::DataModule* m_pDataModule;
        Modules::Map::MapDebugModule* m_pMapDebugModule;
        
        Modules::RoutesModule* m_pRoutesModule;
        Modules::TrafficModule* m_pTrafficModule;
        Modules::AnimatedObjectsModule* m_pAnimatedObjectsModule;
        Modules::IPlatformAbstractionModule& m_platformAbstractionModule;

        Eegeo::Resources::ResourceSpatialQueryService *m_pResourceSpatialQueryService;
        
        Eegeo::Helpers::Jpeg::IJpegLoader& m_jpegLoader;
        
        Eegeo::Location::ILocationService& m_locationService;

        Eegeo::Helpers::GLHelpers::TextureInfo m_placeHolderTexture;
        
        Eegeo::Search::Service::SearchService* m_pSearchService;
        
        Eegeo::UI::NativeUIFactories& m_nativeInputFactories;

        Resources::Roads::Navigation::NavigationGraphDebuggingService* m_pNavGraphDebuggingService;
        
        Eegeo::Web::WebConnectivityValidator* m_pWebConnectivityValidator;
        Eegeo::Web::WebConnectivityErrorHandler* m_pWebConnectivityErrorHandler;
        
        Eegeo::Config::PlatformConfig m_platformConfig;
        
        bool m_waitForInitialLocation;

        void PreDraw(const Rendering::RenderContext& renderContext, Rendering::GLState& glState);
        void DrawWorldPhases(const Rendering::RenderContext& renderContext, Rendering::GLState& glState, Rendering::IRenderableFilter& renderableFilter);
        void DrawAllPhases(const Rendering::RenderContext& renderContext, Rendering::GLState& glState, Rendering::IRenderableFilter& renderableFilter);
        void PostDraw(const Rendering::RenderContext& renderContext, Rendering::GLState& glState);

    public:
        EegeoWorld(const std::string& apiToken,
                   Modules::IPlatformAbstractionModule& platformAbstractionModule,
                   Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader,
                   const Eegeo::Rendering::ScreenProperties& screenProperties,
                   Eegeo::Location::ILocationService& locationService,
                   Eegeo::UI::NativeUIFactories& nativeInputFactories,
                   EnvironmentCharacterSet::Type characterSetType,
                   Eegeo::Config::PlatformConfig platformConfig,

                   //If you intend to use the SearchService, you must provide SearchServiceCredentials for the
                   //default here.com provider, obtainable at http://developer.here.com/plans - note that this
                   //API point will later permit applications to provide their own search service backed by the
                   //provider of their choice
                   Eegeo::Search::Service::SearchServiceCredentials* pSearchCredentials=NULL,
                   IEegeoErrorHandler* pErrorHandler=NULL
                   );

        ~EegeoWorld();

        Eegeo::Debug::FrameTimer& GetFrameTimer() { return *m_pFrameTimer; }
        Eegeo::Debug::FrameTimerVisualiser& GetFrameTimerVisualiser() { return *m_pFrameTimerVisualiser; }
        Eegeo::Debug::Profile::Profiler& GetProfiler() { return *m_pProfiler; }
        Eegeo::Debug::Profile::ProfileVisualiser& GetProfileVisualiser() { return *m_pProfileVisualiser; }
        
        Eegeo::Concurrency::Tasks::IWorkPool& GetWorkPool() { return *m_pWorkPool; }
        
        Eegeo::Resources::ResourceSpatialQueryService &GetResourceSpatialQueryService() { return *m_pResourceSpatialQueryService; }
        
        Eegeo::Resources::Roads::Navigation::NavigationGraphDebuggingService &GetNavigationGraphDebuggingService() { return *m_pNavGraphDebuggingService; }
        
        const Eegeo::Helpers::GLHelpers::TextureInfo& GetEnvironmentPlaceholderTexture() const { return m_placeHolderTexture; }
        
        Eegeo::UI::NativeUIFactories &GetNativeUIFactories() { return m_nativeInputFactories; }
        
        Eegeo::Location::ILocationService &GetLocationService() { return m_locationService; }
        
        Modules::Map::MapModule& GetMapModule() const { return *m_pMapModule; }
        Modules::Map::MapDebugModule& GetMapDebugModule() const { return *m_pMapDebugModule; }
        Modules::Core::CoreModule& GetCoreModule() const { return *m_pCoreModule; }
        Modules::Data::DataModule& GetDataModule() { return *m_pDataModule; }

        Modules::IPlatformAbstractionModule& GetPlatformAbstractionModule() const { return m_platformAbstractionModule; }
        
        Modules::Core::RenderingModule& GetRenderingModule() const { return m_pCoreModule->GetRenderingModule(); }
        Modules::Core::DebugRenderingModule& GetDebugRenderingModule() const { return m_pCoreModule->GetDebugRenderingModule(); }
        Modules::Core::LightingModule& GetLightingModule() const { return m_pCoreModule->GetLightingModule(); }
        Modules::Core::FontsModule& GetFontsModule() const { return m_pCoreModule->GetFontsModule(); }
        Modules::Core::AsyncLoadersModule& GetAsyncLoadersModule() const { return m_pCoreModule->GetAsyncLoadersModule(); }
        Modules::Core::SceneModelsModule& GetSceneModelsModule() const { return m_pCoreModule->GetSceneModelsModule(); }
        
        Modules::Map::Layers::TerrainModelModule& GetTerrainModelModule() const { return m_pMapModule->GetTerrainModelModule(); }
        Modules::Map::Layers::TerrainPresentationModule& GetTerrainPresentationModule() const { return m_pMapModule->GetTerrainPresentationModule(); }
        Modules::Map::Layers::TerrainStreamingModule& GetTerrainStreamingModule() const { return m_pMapModule->GetTerrainStreamingModule(); }

        Modules::Map::Layers::TransportModelModule& GetTransportModelModule() const { return m_pMapModule->GetTransportModelModule(); }
        Modules::Map::Layers::TransportPresentationModule& GetTransportPresentationModule() const { return m_pMapModule->GetTransportPresentationModule(); }
        Modules::Map::Layers::TransportStreamingModule& GetTransportStreamingModule() const { return m_pMapModule->GetTransportStreamingModule(); }

        Modules::Map::Layers::BuildingModelModule& GetBuildingModelModule() const { return m_pMapModule->GetBuildingModelModule(); }
        Modules::Map::Layers::BuildingStreamingModule& GetBuildingStreamingModule() const { return m_pMapModule->GetBuildingStreamingModule(); }
        Modules::Map::Layers::BuildingPresentationModule& GetBuildingPresentationModule() const { return m_pMapModule->GetBuildingPresentationModule(); }
        
        Modules::Map::Layers::PlaceNamesModelModule& GetPlaceNamesModelModule() const { return m_pMapModule->GetPlaceNamesModelModule(); }
        Modules::Map::Layers::PlaceNamesPresentationModule& GetPlaceNamesPresentationModule() const { return m_pMapModule->GetPlaceNamesPresentationModule(); }
        Modules::Map::Layers::PlaceNamesStreamingModule& GetPlaceNamesStreamingModule() const { return m_pMapModule->GetPlaceNamesStreamingModule(); }
        
        Modules::Map::Layers::ShadowModelModule& GetShadowModelModule() const { return m_pMapModule->GetShadowModelModule(); }
        Modules::Map::Layers::ShadowPresentationModule& GetShadowPresentationModule() const { return m_pMapModule->GetShadowPresentationModule(); }
        
        Modules::Map::StreamingModule& GetStreamingModule() const { return m_pMapModule->GetStreamingModule(); }
        Modules::Map::CityThemesModule& GetCityThemesModule() const { return m_pMapModule->GetCityThemesModule(); }
        Modules::Map::EnvironmentMaterialModule& GetEnvironmentMaterialModule() const { return m_pMapModule->GetEnvironmentMaterialModule(); }
        Modules::Map::WeatherModule& GetWeatherModule() const { return m_pMapModule->GetWeatherModule(); }
        Modules::Map::CoverageTreeModule& GetCoverageTreeModule() const { return m_pMapModule->GetCoverageTreeModule(); }

        Modules::TrafficModule& GetTrafficModule() const { return *m_pTrafficModule; }
        Modules::RoutesModule& GetRoutesModule() const { return *m_pRoutesModule; }
        Modules::AnimatedObjectsModule& GetAnimatedObjectsModule() const { return *m_pAnimatedObjectsModule; }
        
        Eegeo::Web::WebConnectivityValidator& GetWebConnectivityValidator() const { return *m_pWebConnectivityValidator; }
        
        bool GetWaitForInitialLocation() const { return m_waitForInitialLocation; }
        void SetWaitForInitialLocation(bool wait) { m_waitForInitialLocation = wait; }
        
        bool IsSearchServiceAvailable() const { return m_pSearchService != NULL; }
        Eegeo::Search::Service::SearchService& GetSearchService() const
        {
            Eegeo_ASSERT(m_pSearchService != NULL, "To use the SearchService, ensure you have provided credentials to the EegeoWorld constructor!\n")
            return *m_pSearchService;
        }
        
        bool IsStreaming(bool includePrecacheService) const;

        const bool Initialising() const;
        
        void EarlyUpdate(float dt);
        void Update(const EegeoUpdateParameters& updateParameters);
        void Draw(const EegeoDrawParameters& drawParameters, Rendering::IRenderableFilter& renderableFilter);
        void Draw(const EegeoDrawParameters& drawParameters);
        void OnPause();
        void OnResume();
        
        float GetInitialisationProgress() const;

        void InitialiseWorldStates(const std::string& apiToken);
        void TeardownWorldStates();
    };
}
