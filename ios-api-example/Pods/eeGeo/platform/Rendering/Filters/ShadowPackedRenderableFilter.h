// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "PackedRenderableFilter.h"
#include "Streaming.h"
#include "Lighting.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Filters
        {
            class ShadowPackedRenderableFilter : public PackedRenderableFilter
            {
            public:
                ShadowPackedRenderableFilter(const Lighting::GlobalShadowing& globalShadowing,
                                             const Scene::ISceneElementSource<Renderables::PackedRenderable>& sceneElementsSource,
                                             const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                             const Streaming::CameraFrustumStreamingVolume& streamingVolume);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
                
            private:
                const Lighting::GlobalShadowing& m_globalShadowing;
            };
        }
    }
}
