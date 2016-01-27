// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IPlaceholderBuilder.h"
#include "Types.h"
#include "Rendering.h"
#include "Resources.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Placeholder
            {
                class TerrainPlaceholderBuilder : public IPlaceholderBuilder, protected Eegeo::NonCopyable
                {
                    public:
                        TerrainPlaceholderBuilder(
                                                  Rendering::MeshFactories::DiffuseMeshFactory& diffuseMeshFactory,
                                                  Rendering::IMaterialProvider& materialProvider,
                                                  Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                                  Rendering::Scene::SceneElementRepository<Rendering::Renderables::WorldMeshRenderable>& sceneElementRepository
                                                  ) :
                                m_diffuseMeshFactory(diffuseMeshFactory),
                                m_materialProvider(materialProvider),
                                m_sceneElementRepository(sceneElementRepository),
                                m_vertexBindingPool(vertexBindingPool)
                        {
                        }
                    
                        IBuiltResource* Build(Eegeo::Streaming::MortonKey key);
                    
                    private:
                        Rendering::MeshFactories::DiffuseMeshFactory& m_diffuseMeshFactory;
                        Rendering::IMaterialProvider& m_materialProvider;
                        Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                        Rendering::Scene::SceneElementRepository<Rendering::Renderables::WorldMeshRenderable>& m_sceneElementRepository;
                };
            }
        }
    }
}