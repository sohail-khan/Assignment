// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Traffic.h"
#include "TrafficCongestion.h"
#include "Location.h"
#include "Camera.h"
#include "AsyncModels.h"
#include "CityThemes.h"
#include "Random.h"
#include "Streaming.h"
#include "Terrain.h"
#include "Navigation.h"
#include "PlatformConfig.h"
#include "Lighting.h"

namespace Eegeo
{
    namespace Modules
    {
        class TrafficModule : protected Eegeo::NonCopyable
        {
        public:
            TrafficModule(Resources::Roads::Navigation::NavigationGraphRepository& roadNavGraphRepository,
                          Resources::Roads::Navigation::NavigationGraphRepository& railNavGraphRepository,
                          Resources::Roads::Navigation::NavigationGraphRepository& tramNavGraphRepository,
                          Streaming::CameraFrustumStreamingVolume& streamingVolume,
                          Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                          Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                          Io::AsyncModels::HttpAsyncModelLoader& asyncModelLoader,
                          Resources::CityThemes::ICityThemesService& cityThemesService,
                          Resources::CityThemes::ThemeStateController& themeStateController,
                          const Config::PlatformConfig& config,
                          Rendering::Materials::NullMaterialFactory& nullMaterialFactory,
                          const Lighting::GlobalLighting& lighting,
                          Lighting::GlobalFogging& fogging,
                          Rendering::RenderableFilters& renderableFilters,
                          const Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                          Rendering::IMaterialProvider& materialProvider,
                          Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                          Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool);
            
            ~TrafficModule();

            static TrafficModule* Create(Eegeo::Modules::Core::CoreModule& coreModule,
                                         Eegeo::Modules::Map::MapModule& mapModule,
                                         const Config::PlatformConfig& config);
            
            void Update(float dt, const Camera::RenderCamera& renderCamera, const dv3& ecefInterestPoint);

            void SetEnabled(bool value);
            bool IsEnabled() const;
            
            TrafficCongestion::TrafficCongestionSimulationController& GetTrafficCongestionSimulationController() const;
            TrafficCongestion::ITrafficCongestionService& GetTrafficCongestionService() const;
            Traffic::TrafficSimulationController& GetTrafficSimulationController() const;
            
        private:
            Random m_random;
            bool m_enabled;
            Traffic::Themes::TrafficThemeModel* m_pTrafficThemeModel;
            Traffic::Themes::TrafficThemeController* m_pTrafficThemeController;
            
            Traffic::TrafficSimulationFactory* m_pTrafficSimulationFactory;
            Eegeo::Traffic::TrafficSimulationController* m_pTrafficSimulationController;
            
            Eegeo::Traffic::VehicleModelNodeRepository* m_pVehicleModelNodeRepository;
            Eegeo::Traffic::VehicleRenderer* m_pTrafficVehicleRenderer;
            Eegeo::Rendering::Materials::NullMaterial* m_pTrafficSimulationNullMaterial;
            
            Eegeo::TrafficCongestion::TrafficCongestionModel* m_pTrafficCongestionModel;
            Eegeo::Traffic::VehicleRenderablesModel* m_pTrafficCongestionVehicleRenderablesModel;
            Eegeo::Traffic::VehicleRenderer* m_pTrafficCongestionVehicleRenderer;
            Eegeo::TrafficCongestion::TrafficCongestionConfig* m_pTrafficCongestionConfig;
            Eegeo::TrafficCongestion::TrafficCongestionSimulationController* m_pTrafficCongestionSimulationController;
            Eegeo::TrafficCongestion::TrafficCongestionVehicleFactory* m_pTrafficCongestionVehicleFactory;
            Eegeo::TrafficCongestion::TrafficCongestionService* m_pTrafficCongestionService;
            
            Rendering::RenderableFilters& m_renderableFilters;
        };
    }
}