// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "IRenderableFilter.h"
#include "ISceneElementCriteriaFilterable.h"
#include "Streaming.h"
#include "Culling.h"
#include "CullingVolumeVisibilityUpdater.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Filters
        {                        
            class PackedRenderableFilter : protected Eegeo::NonCopyable, public IRenderableFilter, Scene::ISceneElementCriteriaFilterable<Renderables::PackedRenderable>
            {
            public:
                PackedRenderableFilter(
                                         const Scene::ISceneElementSource<Renderables::PackedRenderable>& sceneElementsSource,
                                         const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                       const Streaming::CameraFrustumStreamingVolume& streamingVolume);
                
                void SetFilterCriteria(Scene::ISceneElementFilterCriteria<Renderables::PackedRenderable>* pCriteria);
                
                void RemoveFilterCriteria();
                
                virtual void EnqueueRenderables(const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
                
                void SetEnabled(bool enabled);
                
            private:
                const Scene::ISceneElementSource<Renderables::PackedRenderable>& m_sceneElementsSource;
                const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                Culling::CullingVolumeVisibilityUpdater m_cullingVolumeVisibilityUpdater;
                const Streaming::CameraFrustumStreamingVolume& m_streamingVolume;
                const Scene::ISceneElementFilterCriteria<Renderables::PackedRenderable>* m_pFilterCriteria;
                bool m_enabled;
            };
        }
    }
}