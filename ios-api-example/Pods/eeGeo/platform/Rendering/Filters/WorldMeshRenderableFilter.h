// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "IRenderableFilter.h"
#include "ISceneElementCriteriaFilterable.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Filters
        {
            class WorldMeshRenderableFilter : protected Eegeo::NonCopyable, public IRenderableFilter, Scene::ISceneElementCriteriaFilterable<Renderables::WorldMeshRenderable>
            {
            public:
                WorldMeshRenderableFilter(
                                        const Scene::ISceneElementSource<Renderables::WorldMeshRenderable>& sceneElementsSource,
                                        const Rendering::EnvironmentFlatteningService& environmentFlatteningService
                                        );
                
                void SetFilterCriteria(Scene::ISceneElementFilterCriteria<Renderables::WorldMeshRenderable>* pCriteria);
                
                void RemoveFilterCriteria();
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
                
            private:
                const Scene::ISceneElementSource<Renderables::WorldMeshRenderable>& m_sceneElementsSource;
                const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                const Scene::ISceneElementFilterCriteria<Renderables::WorldMeshRenderable>* m_pFilterCriteria;
            };
        }
    }
}