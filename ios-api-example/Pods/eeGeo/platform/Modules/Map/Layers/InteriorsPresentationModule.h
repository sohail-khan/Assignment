// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Modules.h"
#include "Interiors.h"
#include "Rendering.h"
#include "Streaming.h"
#include "InteriorsRenderableFilter.h"
#include "LandmarkToRenderableRepository.h"
#include "Lighting.h"
#include "Pins.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "Terrain.h"
#include "Camera.h"
#include "InteriorsConfiguration.h"
#include "Fonts.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class InteriorsPresentationModule
                {
                public:
                    InteriorsPresentationModule(Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& interiorsSceneElementRepository,
                                                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& buildingsSceneElementRepository,
                                                Lighting::GlobalShadowing& globalShadowing,
                                                Rendering::Filters::PackedRenderableFilter& buildingsRenderableFilter,
                                                Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                Streaming::CameraFrustumStreamingVolume& streamingVolume,
                                                Rendering::RenderableFilters& renderableFilters,
                                                Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                                Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                                Rendering::GlBufferPool& glBufferPool,
                                                Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                                Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                                Rendering::MeshFactories::TextMeshFactory& textMeshFactory,
                                                Resources::Buildings::LandmarkToRenderableRepository& landmarkToRenderableRepository,
                                                Resources::Interiors::InteriorsModelRepository& interiorsModelRepository,
                                                Resources::Interiors::Entities::InteriorsEntitiesRepository& interiorsEntitiesRepository,
                                                Resources::Interiors::Markers::InteriorMarkerModelRepository& interiorMarkerModelRepository,
                                                Resources::Interiors::InteriorsCellResourceObserver& interiorsCellResourceObserver,
                                                Helpers::ITextureFileLoader& textureFileLoader,
                                                Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                                const Eegeo::Rendering::ScreenProperties& screenProperties,
                                                Eegeo::Helpers::IFileIO& fileIO,
                                                Map::Layers::PlaceNamesPresentationModule& placenamesPresentationModule,
                                                Map::Layers::PlaceNamesModelModule& placeNamesModelModule,
                                                const Resources::Interiors::InteriorsConfiguration& interiorsConfig,
                                                bool enableInteriors,
                                                bool interiorsAffectedByFlattening);
                    
                    ~InteriorsPresentationModule();
                    
                    static InteriorsPresentationModule* Create(InteriorsModelModule& interiorsModelModule,
                                                               BuildingModelModule& buildingModelModule,
                                                               BuildingPresentationModule& buildingPresentationModule,
                                                               Core::LightingModule& lightingModule,
                                                               Core::RenderingModule& renderingModule,
                                                               Helpers::ITextureFileLoader& textureFileLoader,
                                                               TerrainModelModule& terrainModelModule,
                                                               Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                               Streaming::CameraFrustumStreamingVolume& streamingVolume,
                                                               const Eegeo::Rendering::ScreenProperties& screenProperties,
                                                               Eegeo::Helpers::IFileIO& fileIO,
                                                               Map::Layers::PlaceNamesPresentationModule& placenamesPresentationModule,
                                                               Map::Layers::PlaceNamesModelModule& placeNamesModelModule,
                                                               const Resources::Interiors::InteriorsConfiguration& interiorsConfig,
                                                               bool enableInteriors,
                                                               bool interiorsAffectedByFlattening);
                    
                    static Resources::Interiors::InteriorsConfiguration DefaultConfig();
                    
                    Resources::Interiors::InteriorController& GetController() const;
                    
                    Rendering::Filters::InteriorsRenderableFilter& GetInteriorsRenderableFilter() const;
                    
                    Resources::Interiors::InteriorSelectionModel& GetInteriorSelectionModel() const;

                    void Update(float dt, const Eegeo::Camera::RenderCamera& renderCamera);
                    
                    Resources::Interiors::Entities::IInteriorsLabelController& GetInteriorsLabelsController() const;
                    Fonts::FontInstance& GetLabelFont() const;
                    
                    const Resources::Interiors::InteriorsConfiguration& GetConfig() const;
                    
                    
                private:
                    
                    const Resources::Interiors::InteriorsConfiguration m_interiorsConfig;
                    
                    Resources::Interiors::InteriorSelectionModel* m_pInteriorSelectionModel;
                    
                    Eegeo::Rendering::Shaders::ColorShader* m_pQuadShader;
                    Eegeo::Rendering::Materials::DepthlessColorMaterial* m_pQuadMaterial;
                    Eegeo::Rendering::Renderables::WorldMeshRenderable* m_pQuadRenderable;
                    Rendering::Filters::InteriorsRenderableFilter* m_pInteriorsRenderableFilter;
                    
                    Resources::Interiors::InteriorController* m_pController;
                    
                    Fonts::FontInstance* m_pLabelFont;
                    Resources::Interiors::Entities::IInteriorsLabelController* m_pInteriorsLabelsController;
                };
            }
        }
    }
}