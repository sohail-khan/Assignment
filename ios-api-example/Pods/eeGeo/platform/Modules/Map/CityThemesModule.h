// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Location.h"
#include "CityThemes.h"
#include "Lighting.h"
#include "Web.h"
#include "AsyncTexturing.h"
#include "Weather.h"
#include "Camera.h"
#include "AnimatedObjects.h"
#include "VectorMathDecl.h"
#include "Tasks.h"
#include "IEegeoErrorHandler.h"
#include "NativeUIFactories.h"
#include "ConfigSections.h"
#include "CityThemes.h"
#include <vector>
#include "IFileIO.h"

#include <string>

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            class CityThemesModule : protected Eegeo::NonCopyable
            {
            public:
                CityThemesModule(Rendering::EnvironmentMaterialRepository& materialRepository,
                                 Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& buildingsRenderables,
                                 Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& transportRenderables,
                                 Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& terrainRenderables,
                                 Lighting::GlobalLighting& globalLighting,
                                 Lighting::GlobalFogging& globalFogging,
                                 Lighting::GlobalShadowing& globalShadowing,
                                 Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                 Rendering::AsyncTexturing::HttpAsyncTextureLoader& asyncTextureLoader,
                                 Eegeo::Weather::WeatherOverlayController & weatherOverlayController,
                                 Rendering::Materials::WeatherOverlayMaterial2& weatherOverlayMaterial,
                                 Rendering::EnvironmentTextures& environmentTextures,
                                 Web::IWebLoadRequestFactory& webRequestFactory,
                                 Helpers::ITextureFileLoader& textureLoader,
                                 Helpers::IHttpCache& httpCache,
                                 Eegeo::Concurrency::Tasks::IWorkPool& workPool,
                                 const Config::CityThemesConfigSection& cityThemesConfig,
                                 IEegeoErrorHandler* pErrorHandler,
                                 UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                                 Helpers::IFileIO& fileIO);
                
                ~CityThemesModule();
                
                static CityThemesModule* Create(Core::RenderingModule& renderingModule,
                                                Core::LightingModule& lightingModule,
                                                Core::AsyncLoadersModule& asyncLoadersModule,
                                                WeatherModule& weatherModule,
                                                EnvironmentMaterialModule& environmentMaterialModule,
                                                Layers::BuildingModelModule& buildingModelModule,
                                                Layers::TransportModelModule& transportModelModule,
                                                Layers::TerrainModelModule& terrainModelModule,
                                                Web::IWebLoadRequestFactory& webRequestFactory,
                                                Helpers::ITextureFileLoader& textureLoader,
                                                Helpers::IHttpCache& httpCache,
                                                Eegeo::Concurrency::Tasks::IWorkPool& workPool,
                                                const Config::CityThemesConfigSection& cityThemesConfig,
                                                IEegeoErrorHandler* pErrorHandler,
                                                UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                                                Helpers::IFileIO& fileIO);


                void LoadEmbeddedTheme(const dv3& cameraEcefLocation);
                void LoadStreamedManifest();
                void LoadStreamedManifest(const std::string& manifestUrl);
                void TryApplyEmbeddedTheme(const dv3& cameraEcefLocation);
                void Update(float dt, const dv3& cameraEcefLocation, const dv3& ecefInterestPoint);
                bool IsMissingThemeData() const;
                
                Resources::CityThemes::ThemeStateTransitionController &GetThemeStateTransitionController() const;
                Resources::CityThemes::ICityThemesService& GetCityThemesService() const;
                Resources::CityThemes::ICityThemesUpdater& GetCityThemesUpdater() const;
                Resources::CityThemes::ICityThemeRepository& GetCityThemesRepository() const;
                Resources::CityThemes::ThemeStateController& GetThemeStateController() const;
                Resources::CityThemes::CityThemeLoader& GetCityThemeLoader() const;
                Resources::CityThemes::CityThemesAnimatedObjectsLoader& GetCityThemesAnimatedObjectsLoader() const;
                Resources::CityThemes::CityThemesTextureUpdater& GetCityThemesTextureUpdater() const;
                
            private:
                const Config::CityThemesConfigSection m_cityThemesConfig;
                Helpers::IFileIO& m_fileIO;
                
                Resources::CityThemes::ThemeStateController *m_pThemeStateController;
                Resources::CityThemes::ThemeChangeController *m_pThemeChangeController;
                Resources::CityThemes::ThemeStateTransitionController *m_pThemeStateTransitionController;
                Resources::CityThemes::CityThemeRepository* m_pCityThemesRepository;
                Resources::CityThemes::CityThemesTextureUpdater* m_pCityThemesTextureUpdater;
                Resources::CityThemes::CityThemesService* m_pCityThemesService;
                Resources::CityThemes::CityThemesUpdater* m_pCityThemesUpdater;
                Resources::CityThemes::CityThemesAnimatedObjectsLoader* m_pCityThemesAnimatedObjectsLoader;
                Resources::CityThemes::CityThemeLoader* m_pCityThemeLoader;
                Resources::CityThemes::CityThemesMissingDataHandler* m_pCityThemesMissingDataHandler;
            };
        }
    }
}