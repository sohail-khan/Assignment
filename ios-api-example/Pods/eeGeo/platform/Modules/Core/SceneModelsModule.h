// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Lighting.h"
#include "Modules.h"
#include "DebugRendering.h"
#include "SceneModelFactory.h"
#include "Helpers.h"
#include "AsyncModels.h"
#include "Web.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class SceneModelsModule : protected Eegeo::NonCopyable
            {
            public:
                SceneModelsModule(Rendering::GlBufferPool& glBufferPool,
                                  Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                  Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                  Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                  Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                  Lighting::GlobalLighting& globalLighting,
                                  Lighting::GlobalFogging& globalFogging,
                                  Helpers::IFileIO& fileIO,
                                  Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                  Helpers::IHttpCache& httpCache,
                                  Rendering::AsyncTexturing::LocalAsyncTextureLoader& localAsyncTextureLoader,
                                  Rendering::AsyncTexturing::HttpAsyncTextureLoader& httpAsyncTextureLoader,
                                  Rendering::RenderableFilters& renderableFilters,
                                  DebugRendering::DebugRenderer& debugRenderer);
                ~SceneModelsModule();
                
                static SceneModelsModule* Create(RenderingModule& renderingModule,
                                                 LightingModule& lightingModule,
                                                 DebugRenderingModule& debugRenderingModule,
                                                 AsyncLoadersModule& asyncLoadersModule,
                                                 Helpers::IFileIO& fileIO,
                                                 Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                                 Helpers::IHttpCache& httpCache);
                
                void ReleaseUnusedResources();
                
                Rendering::SceneModels::SceneModelLoader& GetLocalModelLoader() const { return *m_pLocalFileLoader; }
                Io::AsyncModels::HttpAsyncModelLoader& GetAsyncModelLoader() const { return *m_pAsyncModelLoader; }
                
                Rendering::SceneModels::SceneModelFactory& GetLocalSceneModelFactory() const { return *m_pLocalFactory; }
                Rendering::SceneModels::SceneModelFactory& GetHttpSceneModelFactory() const { return *m_pHttpFactory; }
                
                Rendering::SceneModels::SceneModelFactory::TTextureRepo& GetTextureResourceRepository() const { return *m_pTextureRepo; }
                Rendering::SceneModels::SceneModelFactory::TMaterialRepo& GetMaterialResourceRepository() const { return *m_pMaterialRepo; }
                Rendering::SceneModels::SceneModelFactory::TMeshRepo& GetMeshResourceRepository() const { return *m_pMeshRepo; }
                Rendering::SceneModels::SceneModelFactory::TTriStripMeshRepo& GetTriStripMeshResourceRepository() const { return *m_pTriStripMeshRepo; }
                Rendering::Filters::SceneModelRenderableFilter& GetSceneModelRenderableFilter() const { return *m_pSceneModelRenderableFilter; }
    

            private:
                
                Rendering::SceneModels::SceneModelLoader* m_pLocalFileLoader;
                Rendering::SceneModels::SceneModelFactory* m_pLocalFactory;
                Rendering::SceneModels::SceneModelFactory* m_pHttpFactory;
                Rendering::SceneModels::SceneModelFactory::TTextureRepo* m_pTextureRepo;
                Rendering::SceneModels::SceneModelFactory::TMaterialRepo* m_pMaterialRepo;
                Rendering::SceneModels::SceneModelFactory::TMeshRepo* m_pMeshRepo;
                Rendering::SceneModels::SceneModelFactory::TTriStripMeshRepo* m_pTriStripMeshRepo;
                Rendering::MeshFactories::SceneModelMeshFactory* m_pMeshFactory;
                Rendering::Filters::SceneModelRenderableFilter* m_pSceneModelRenderableFilter;
 
                Io::AsyncModels::HttpAsyncModelLoader* m_pAsyncModelLoader;
                
                Rendering::RenderableFilters& m_renderableFilters;
            };
        }
    }
}