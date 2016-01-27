// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Lighting.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class ShadowPresentationModule : protected Eegeo::NonCopyable
                {
                public:
                    
                    ShadowPresentationModule(Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                             Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                             Rendering::GlBufferPool& glBufferPool,
                                             Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                             Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                             Rendering::Filters::RenderableRepository& renderableRepository,
                                             Rendering::Shaders::ColorShader& colorShader,
                                             Lighting::GlobalShadowing& globalShadowing,
                                             Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& shadowSceneElementRepository,
                                             const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                             const Streaming::CameraFrustumStreamingVolume& streamingVolume);
                    
                    ~ShadowPresentationModule();
                    
                    static ShadowPresentationModule* Create(Core::RenderingModule& renderingModule,
                                                            Core::LightingModule& lightingModule,
                                                            ShadowModelModule& shadowModelModule,
                                                            const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                            const Streaming::CameraFrustumStreamingVolume& streamingVolume);
                    
                    Rendering::Filters::PackedRenderableFilter& GetShadowRenderableFilter() const;
                    Rendering::Materials::ShadowMaterial& GetShadowOverlayMaterial() const;
                    Rendering::Renderables::WorldMeshRenderable& GetShadowOverlayRenderable() const;
                private:
                    Rendering::Filters::ShadowPackedRenderableFilter* m_pShadowPackedRenderableFilter;
                    Rendering::Materials::ShadowMaterial* m_pShadowOverlayMaterial;
                    Rendering::Renderables::WorldMeshRenderable* m_pShadowOverlayRenderable;
                };
            }
        }
    }
}