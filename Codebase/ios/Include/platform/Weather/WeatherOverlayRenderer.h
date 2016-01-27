// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Weather.h"
#include "Rendering.h"
#include "IRenderableFilter.h"


namespace Eegeo
{
    namespace Weather
    {
        class WeatherOverlayRenderer : Eegeo::NonCopyable, public Rendering::IRenderableFilter
        {
        public:
            WeatherOverlayRenderer(Rendering::Renderables::WorldMeshRenderable& overlayRenderable, WeatherOverlayController& weatherController);
            void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);

        private:
            Rendering::Renderables::WorldMeshRenderable& m_overlayRenderable;
            WeatherOverlayController& m_weatherController;
        };
    }
}
