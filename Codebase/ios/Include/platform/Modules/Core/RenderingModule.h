// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "GLState.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class RenderingModule : protected Eegeo::NonCopyable
            {
            public:
                RenderingModule(const bool bufferPoolingEnabled);
                ~RenderingModule();
                static RenderingModule* Create(const bool bufferPoolingEnabled);
                
                Rendering::GlBufferPool& GetGlBufferPool() const;
                Rendering::VertexLayouts::VertexLayoutPool& GetVertexLayoutPool() const;
                Rendering::VertexLayouts::VertexBindingPool& GetVertexBindingPool() const;
                Rendering::RenderQueue& GetRenderQueue() const;
                Rendering::RenderableFilters& GetRenderableFilters() const;
                Rendering::Shaders::ShaderIdGenerator& GetShaderIdGenerator() const;
                Rendering::Materials::MaterialIdGenerator& GetMaterialIdGenerator() const;
                Rendering::Materials::NullMaterialFactory& GetNullMaterialFactory() const;
                Rendering::Filters::RenderableRepository& GetRenderableRepository() const;
                Rendering::MeshFactories::TextMeshFactory& GetTextMeshFactory() const;
                Rendering::MeshFactories::DiffuseMeshFactory& GetDiffuseMeshFactory() const;
                Rendering::MeshFactories::PackedTwoTextureDiffuseMeshFactory& GetPackedTwoTextureDiffuseMeshFactory() const;
                Rendering::MeshFactories::PositionMeshFactory& GetPositionMeshFactory() const;
                Rendering::Shaders::ColorShader& GetColorShader() const;
                Rendering::StencilLayersController& GetStencilLayersController() const;
                
                //! \deprecated use of this shared material instance in app code can cause
                //! unintended side-effects in render state. Use GetNullMaterialFactory().Create() instead.
                Rendering::Materials::NullMaterial& GetNullMaterial() const;
            private:
                Rendering::GlBufferPool* m_pGlBufferPool;
                Rendering::VertexLayouts::VertexLayoutPool* m_pVertexLayoutPool;
                Rendering::VertexLayouts::VertexBindingPool* m_pVertexBindingPool;
                Rendering::RenderQueue* m_pRenderQueue;
                Rendering::RenderableFilters* m_pRenderableFilters;
                Rendering::Shaders::ShaderIdGenerator* m_pShaderIdGenerator;
                Rendering::Materials::MaterialIdGenerator* m_pMaterialIdGenerator;
                Rendering::Materials::NullMaterialFactory* m_pNullMaterialFactory;
                Rendering::Shaders::NullShader* m_pNullShader;
                Rendering::Materials::NullMaterial* m_pSingletonNullMaterialDeprecated;
                Rendering::MeshFactories::PackedTwoTextureDiffuseMeshFactory* m_pPackedTwoTextureDiffuseMeshFactory;
                Rendering::MeshFactories::DiffuseMeshFactory* m_pDiffuseMeshFactory;
                Rendering::MeshFactories::TextMeshFactory* m_pTextMeshFactory;
                Rendering::MeshFactories::PositionMeshFactory* m_pPositionMeshFactory;
                Rendering::Filters::RenderableRepository* m_pRenderableRepository;
                Rendering::Shaders::ColorShader* m_pColorShader;
                Rendering::StencilLayersController* m_pStencilLayersController;
            };
        }
    }
}
