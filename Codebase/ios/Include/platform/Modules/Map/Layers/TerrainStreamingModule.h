// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Terrain.h"
#include "Collision.h"
#include "Rendering.h"
#include "Helpers.h"
#include "Modules.h"
#include "IJpegLoader.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class TerrainStreamingModule : protected Eegeo::NonCopyable
                {
                public:
                    TerrainStreamingModule(Rendering::MeshFactories::DiffuseMeshFactory& diffuseMeshFactory,
                                           Rendering::MeshFactories::PackedTwoTextureDiffuseMeshFactory& packedTwoTextureDiffuseMeshFactory,
                                           Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                           Rendering::Scene::SceneElementRepository<Rendering::Renderables::WorldMeshRenderable>& rasterTerrainSceneElementRepository,
                                           Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& lcmSceneElementRepository,
                                           Resources::Terrain::Heights::TerrainHeightRepository& terrainHeightRepository,
                                           Rendering::IMaterialProvider& materialProvider,
                                           Rendering::MeshFactories::LcmReadMeshFactory& lcmReadMeshFactory,
                                           Collision::CollisionMeshResourceRepository& terrainCollisionMeshResourceRepository,
                                           Collision::CollisionMeshResourceRepository& treesCollisionMeshResourceRepository,
                                           Helpers::ITextureFileLoader& textureLoader,
                                           Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader,
                                           const bool manuallyGenerateMipmaps,
                                           const bool generateTreeCollision);
                    
                    ~TerrainStreamingModule();
                    
                    static TerrainStreamingModule* Create(Core::RenderingModule& renderingModule,
                                                          TerrainModelModule& terrainModelModule,
                                                          EnvironmentMaterialModule& environmentMaterialModule,
                                                          Rendering::MeshFactories::LcmReadMeshFactory& lcmReadMeshFactory,
                                                          Helpers::ITextureFileLoader& textureLoader,
                                                          Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader,
                                                          const bool manuallyGenerateMipmaps,
                                                          const bool generateTreeCollision);
                    
                    Resources::Terrain::lcm::ChunkedLcmTerrainBuilder& GetChunkedLcmTerrainBuilder() const;
                    Resources::Terrain::Raster::RasterTerrainBuilder& GetRasterTerrainBuilder() const;
                    Resources::Terrain::Placeholder::TerrainPlaceholderBuilder& GetTerrainPlaceholderBuilder() const;
                    Resources::Terrain::TerrainStreaming& GetTerrainStream() const;
                    
                private:
                    Resources::Terrain::lcm::ChunkedLcmTerrainBuilder* m_pChunkedLcmTerrainBuilder;
                    Resources::Terrain::Raster::RasterTerrainBuilder* m_pRasterTerrainBuilder;
                    Resources::Terrain::Placeholder::TerrainPlaceholderBuilder* m_pTerrainPlaceholderBuilder;
                    Resources::Terrain::TerrainStreaming* m_pTerrainStream;
                };
            }
        }
    }
}