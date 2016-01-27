// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IResourceBuilder.h"
#include "Rendering.h"
#include "Terrain.h"
#include "Helpers.h"
#include "ChunkedFileFormat.h"
#include "Space.h"
#include "Graphics.h"
#include "Collision.h"
#include "CollisionBvhFactory.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace lcm
            {
                const int MAX_QUADTREE_DEPTH_FOR_DETAILED_TEXTURES = 13;
                const int MIN_QUADTREE_DEPTH_FOR_LIGHTMAPS = 11;
                
                enum LcmRenderableItemMaterialType
                {
                    TERRAIN,
                    TREES,
                    TREES_TOP
                };
                
                struct LcmRenderableItemBuilderOutput
                {
                    Rendering::Renderables::PackedRenderable* renderable;
                    int lcmCode;
                    
                    LcmRenderableItemBuilderOutput(int lcm,
                                                   Rendering::Renderables::PackedRenderable* renderable = NULL)
                    : lcmCode(lcm)
                    , renderable(renderable)
                    {
                    }
                };
                
                struct ChunkedLcmTerrainBuilderOutput
                {
                    ChunkedLcmTerrainBuilderOutput()
                    : pTerrainCollisionBvh(NULL)
                    , pTreesCollisionBvh(NULL)
                    , glowmapTextureId(0)
                    , nodeDepth(0)
                    , needsLegacyTerrainCollisionFixup(false)
                    {
                    }
                    
                    ~ChunkedLcmTerrainBuilderOutput();
                    
                    void Clear();
                    
                    Eegeo::Collision::CollisionBvh* pTerrainCollisionBvh;
                    Eegeo::Collision::CollisionBvh* pTreesCollisionBvh;
                    bool needsLegacyTerrainCollisionFixup;
                    std::vector<LcmRenderableItemBuilderOutput> renderables;
                    GLuint glowmapTextureId;
                    int nodeDepth;
                    std::string keyString;
                };
                
                class ChunkedLcmTerrainBuilder : protected Eegeo::NonCopyable, public IResourceBuilder
                {
                    Rendering::MeshFactories::PackedTwoTextureDiffuseMeshFactory& m_packedTwoTextureDiffuseMeshFactory;
                    Rendering::MeshFactories::LcmReadMeshFactory& m_lcmReadMeshFactory;

                    Heights::TerrainHeightRepository& m_terrainHeightRepository;
                    Eegeo::Collision::CollisionMeshResourceRepository& m_terrainCollisionMeshResourceRepository;
                    Eegeo::Collision::CollisionMeshResourceRepository& m_treesCollisionMeshResourceRepository;
                    Eegeo::Helpers::ITextureFileLoader& m_textureLoader;
                    Rendering::IMaterialProvider& m_materialProvider;
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& m_sceneElementRepository;
                    Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                    
                    const bool m_bGenerateTreesCollision;
                    Eegeo::Collision::CollisionBvhFactory m_terrainCollisionBvhFactory;
                    Eegeo::Collision::CollisionBvhFactory m_treesCollisionBvhFactory;
                    
                public:
                    ChunkedLcmTerrainBuilder(
                                             Rendering::MeshFactories::PackedTwoTextureDiffuseMeshFactory& packedTwoTextureDiffuseMeshFactory,
                                             Rendering::MeshFactories::LcmReadMeshFactory& lcmReadMeshFactory,
                                             Heights::TerrainHeightRepository& terrainHeightRepository,
                                             Eegeo::Collision::CollisionMeshResourceRepository& terrainCollisionMeshResourceRepository,
                                             Eegeo::Collision::CollisionMeshResourceRepository& treesCollisionMeshResourceRepository,
                                             bool generateTreesCollision,
                                             Eegeo::Helpers::ITextureFileLoader& textureLoader,
                                             Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& sceneElementRepository,
                                             Rendering::IMaterialProvider& materialProvider,
                                             Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool
                                             );
                    
                    virtual bool Flush(const Streaming::MortonKey& key, void* input, TBuiltResources& result);
                    virtual void DestroyBuiltResource(const Streaming::MortonKey& key, void* input);
                    virtual void* BuildResource(const Streaming::MortonKey& key, const Byte* data, size_t length);
                    virtual bool AcceptsErroredRequests()
                    {
                        return true;
                    }
                private:
                    bool LoadGlowmapTextureChunk(IO::ChunkedFileFormat::ChunkStream& chunkStream, BinaryParsing::membuf& streamBuf, u32& glowMapTextureId);

                    void GetWaterMaterialFromLcmCode(int lcmCode, int nodeDepth, std::string& materialName);
                    void GetLegacyGroundMaterialFromLcmCode(int lcmCode,
                                                            int nodeDepth,
                                                            LcmRenderableItemMaterialType type,
                                                            std::string& materialName);
                    


                    void BuildLcmTerrainFromQuantizedMeshSet(IO::ChunkedFileFormat::ChunkStream& chunkStream,
                                                             BinaryParsing::membuf& streamBuf,
                                                             const Space::CubeMap::CubeMapCellInfo& cellInfo,
                                                             ChunkedLcmTerrainBuilderOutput& builderOutput);
                    
                    void BuildTreesFromQuantizedMeshSet(IO::ChunkedFileFormat::ChunkStream& chunkStream,
                                                        BinaryParsing::membuf& streamBuf,
                                                        const Space::CubeMap::CubeMapCellInfo& cellInfo,
                                                        ChunkedLcmTerrainBuilderOutput& builderOutput);
                    
                    LcmRenderableItemBuilderOutput CreateRenderableItemBuilderOutputForTree(                                                                                                                      const Space::CubeMap::CubeMapCellInfo& cellInfo,
                        bool resourceHasGlowmap,
                        const IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::ReaderMeshResult& meshResult);

                    
                    LcmRenderableItemBuilderOutput CreateRenderableItemBuilderOutputForLcmTerrain(
                        const Space::CubeMap::CubeMapCellInfo& cellInfo,
                        bool resourceHasGlowmap,
                        const IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::ReaderMeshResult& meshResult);
                    
                    
                    LcmRenderableItemBuilderOutput CreateRenderableItemBuilderOutputForWater(                                                                                                                      const Space::CubeMap::CubeMapCellInfo& cellInfo,
                                                                                            bool resourceHasGlowmap,
                                                                                            const IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::ReaderMeshResult& meshResult);
                    
                    public:
                        static int LcmCodeFromMaterialName(const std::string& materialName);
                        static bool IsWaterLcmCode(int lcmCode);
                        static bool IsLod(const Space::CubeMap::CubeMapCellInfo& cellInfo);
                };
            }
        }
    }
}