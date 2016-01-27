// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "HeatmapViewFactory.h"
#include "HeatmapController.h"
#include "HeatmapRenderer.h"
#include "RenderableFilters.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Data
        {
            class HeatmapModule : private Eegeo::NonCopyable
            {
            public:
                static HeatmapModule* Create(Modules::Core::RenderingModule& renderingModule);
                
                HeatmapModule(
                               Eegeo::Data::Heatmaps::HeatmapController* pController,
                               Eegeo::Data::Heatmaps::HeatmapViewFactory* pViewFactory,
                               Eegeo::Data::Heatmaps::HeatmapRenderer* pRenderer,
                               Eegeo::Rendering::RenderableFilters& renderableFilters);
                
                ~HeatmapModule();
                
                Eegeo::Data::Heatmaps::HeatmapController& GetController() { return *m_pController; }
                Eegeo::Data::Heatmaps::HeatmapViewFactory& GetViewFactory() { return *m_pViewFactory; }
                Eegeo::Data::Heatmaps::HeatmapRenderer& GetRenderer() { return *m_pRenderer; }
                
            private:
                Eegeo::Data::Heatmaps::HeatmapController* m_pController;
                Eegeo::Data::Heatmaps::HeatmapViewFactory* m_pViewFactory;
                Eegeo::Data::Heatmaps::HeatmapRenderer* m_pRenderer;
                Eegeo::Rendering::RenderableFilters& m_renderableFilters;
            };
        }
    }
}

