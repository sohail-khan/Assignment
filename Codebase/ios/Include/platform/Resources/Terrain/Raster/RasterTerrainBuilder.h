// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IResourceBuilder.h"
#include "Rendering.h"
#include "Terrain.h"
#include "Streaming.h"
#include "IJpegLoader.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Raster
            {
                struct TerrainBuilderOutput
                {
                    TerrainBuilderOutput(Rendering::Renderables::UniqueTextureRenderable* renderable, RasterTerrainHeightLookup* rasterTerrainHeightLookup)
                    :renderable(renderable)
                    ,rasterTerrainHeightLookup(rasterTerrainHeightLookup)
                    {}
                    
                    RasterTerrainHeightLookup* rasterTerrainHeightLookup;
                    
                    Rendering::Renderables::UniqueTextureRenderable* renderable;
                };
                
                class RasterTerrainBuilder : protected Eegeo::NonCopyable, public IResourceBuilder
                {
                    Eegeo::Rendering::MeshFactories::DiffuseMeshFactory& m_diffuseMeshFactory;
                    Rendering::IMaterialProvider& m_materialProvider;
                    Heights::TerrainHeightRepository& m_terrainHeightRepository;
                    Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                    Eegeo::Helpers::Jpeg::IJpegLoader& m_jpegLoader;
                    Rendering::Scene::SceneElementRepository<Rendering::Renderables::WorldMeshRenderable>& m_sceneElementRepository;
                    
                    const bool m_manuallyGenerateMipmaps;
                    
                public:
                    RasterTerrainBuilder(Eegeo::Rendering::MeshFactories::DiffuseMeshFactory& diffuseMeshFactory,
                                         Rendering::IMaterialProvider& materialProvider,
                                         Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                         Heights::TerrainHeightRepository& terrainHeightRepository,
                                         Rendering::Scene::SceneElementRepository<Rendering::Renderables::WorldMeshRenderable>& sceneElementRepository,
                                         Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader,
                                         const bool manuallyGenerateMipmaps)
                    : m_diffuseMeshFactory(diffuseMeshFactory)
                    , m_terrainHeightRepository(terrainHeightRepository)
                    , m_materialProvider(materialProvider)
                    , m_vertexBindingPool(vertexBindingPool)
                    , m_sceneElementRepository(sceneElementRepository)
                    , m_jpegLoader(jpegLoader)
                    , m_manuallyGenerateMipmaps(manuallyGenerateMipmaps)
                    { }
                    
                    virtual bool Flush(const Streaming::MortonKey& key, void* input, TBuiltResources& result);
                    virtual void DestroyBuiltResource(const Streaming::MortonKey& key, void* input);

                    virtual void* BuildResource(const Streaming::MortonKey& key, const Byte* data, size_t length);
                    virtual bool AcceptsErroredRequests()
                    {
                        return true;
                    }
                };
            }
        }
    }
}