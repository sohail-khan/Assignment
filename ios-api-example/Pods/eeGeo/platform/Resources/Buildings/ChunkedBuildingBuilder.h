// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Types.h"
#include "IResourceBuilder.h"
#include "CityThemes.h"
#include "AsyncTexturing.h"
#include "Streaming.h"
#include "ChunkedFileFormat.h"
#include "Space.h"
#include "Collision.h"
#include "CollisionBvhFactory.h"
#include "LandmarkToRenderableRepository.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Buildings
        {
            typedef std::vector<Rendering::Renderables::PackedRenderable*> TNewRenderableItemVector;
            typedef std::vector<Rendering::Renderables::CustomLandmarkRenderable*> TNewLandmarkRenderablesVector;
            typedef std::vector<Rendering::Renderables::PackedShadowRenderable*> TNewShadowRenderableItemVector;
            
            struct ChunkedBuildingBuilderOutput
            {
                ChunkedBuildingBuilderOutput()
                : lowLod(false)
                , pCollisionBvh(NULL)
                {
                }
                
                ~ChunkedBuildingBuilderOutput();
                
                void Clear();
                
                bool lowLod;
                std::vector<std::string> buildingMaterialNames;
                TNewShadowRenderableItemVector newShadowRenderables;
                TNewRenderableItemVector newBuildingRenderables;
                TNewLandmarkRenderablesVector newLandmarkRenderables;
                Eegeo::Collision::CollisionBvh* pCollisionBvh;
            };
            
            class ChunkedBuildingBuilder : protected Eegeo::NonCopyable, public IResourceBuilder
            {


            public:
                ChunkedBuildingBuilder(
                                       Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                       Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& sceneElementRepository,
                                       Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& shadowSceneElementRepository,
                                       Eegeo::Collision::CollisionMeshResourceRepository& collisionMeshResourceRepository,
                                       bool generateCollision,
                                       Rendering::IMaterialProvider& materialProvider,
                                       Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                       Resources::CityThemes::ICityThemesService& cityThemeService,
                                       Rendering::AsyncTexturing::HttpAsyncTextureLoader& asyncTextureLoader,
                                       Resources::Buildings::LandmarkToRenderableRepository& landmarkToRenderableRepository
                                       )
                : m_packedDiffuseReadMeshFactory(packedDiffuseReadMeshFactory)
                , m_sceneElementRepository(sceneElementRepository)
                , m_shadowSceneElementRepository(shadowSceneElementRepository)
                , m_collisionMeshResourceRepository(collisionMeshResourceRepository)
                , m_bGenerateCollision(generateCollision)
                , m_materialProvider(materialProvider)
                , m_vertexBindingPool(vertexBindingPool)
                , m_cityThemeService(cityThemeService)
                , m_asyncTextureLoader(asyncTextureLoader)
                , m_collisionBvhFactory(Eegeo::Collision::CollisionGroup::Buildings)
                , m_landmarkToRenderableRepository(landmarkToRenderableRepository)
                {
                }
                
                virtual bool Flush(const Streaming::MortonKey& key, void* input, TBuiltResources& result);
                virtual void DestroyBuiltResource(const Streaming::MortonKey& key, void* input);
                virtual void* BuildResource(const Streaming::MortonKey& key, const Byte* data, size_t length);

                virtual bool AcceptsErroredRequests()
                {
                    return false;
                }
                
            private:
                
                bool IsAlpha(const std::string &textureName) const;
                
                void BuildFromQuantizedMeshSet(const Space::CubeMap::CubeMapCellInfo& cellInfo, IO::ChunkedFileFormat::ChunkStream& chunkStream, Resources::BinaryParsing::membuf& membuf, int cellModelChunkChildCount, ChunkedBuildingBuilderOutput& builderOutput);
                
                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& m_sceneElementRepository;
                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& m_shadowSceneElementRepository;
                Eegeo::Collision::CollisionMeshResourceRepository& m_collisionMeshResourceRepository;
                Rendering::IMaterialProvider& m_materialProvider;
                Resources::CityThemes::ICityThemesService& m_cityThemeService;
                Rendering::AsyncTexturing::HttpAsyncTextureLoader& m_asyncTextureLoader;
                Collision::CollisionBvhFactory m_collisionBvhFactory;
                Rendering::MeshFactories::PackedDiffuseReadMeshFactory& m_packedDiffuseReadMeshFactory;
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                Resources::Buildings::LandmarkToRenderableRepository& m_landmarkToRenderableRepository;
                const bool m_bGenerateCollision;
             };
        }
    }
}
