// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Buildings.h"
#include "Modules.h"
#include "Rendering.h"
#include "Collision.h"
#include "CityThemes.h"
#include "AsyncTexturing.h"
#include "LandmarkToRenderableRepository.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class BuildingStreamingModule : protected Eegeo::NonCopyable
                {
                public:
                    BuildingStreamingModule(Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                            Rendering::IMaterialProvider& materialProvider,
                                            Resources::CityThemes::ICityThemesService& cityThemeService,
                                            Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                            Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& buildingSceneElementRepository,
                                            Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& shadowSceneElementRepository,
                                            Eegeo::Collision::CollisionMeshResourceRepository& collisionMeshResourceRepository,
                                            Rendering::AsyncTexturing::HttpAsyncTextureLoader& asyncTextureLoader,
                                            Resources::Buildings::LandmarkToRenderableRepository& landmarkToRenderableRepository,
                                            const bool generateCollision);
                    
                    ~BuildingStreamingModule();
                    
                    static BuildingStreamingModule* Create(Core::RenderingModule& renderingModule,
                                                           Core::AsyncLoadersModule& asyncLoadersModule,
                                                           EnvironmentMaterialModule& environmentMaterialModule,
                                                           BuildingModelModule& buildingModelModule,
                                                           CityThemesModule& cityThemesModule,
                                                           ShadowModelModule& shadowModelModule,
                                                           Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                                           const bool generateCollision);
                    
                    Resources::Buildings::ChunkedBuildingBuilder& GetBuildingBuilder() const;
                    Resources::Buildings::BuildingStreaming& GetBuildingStream() const;
                private:
                    Resources::Buildings::ChunkedBuildingBuilder* m_pBuildingBuilder;
                    Resources::Buildings::BuildingStreaming* m_pBuildingStream;
                };
            }
        }
    }
}