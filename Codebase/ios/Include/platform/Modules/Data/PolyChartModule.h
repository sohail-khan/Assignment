// Copyright eeGeo Ltd 2015, All Rights Reserved

#pragma once

#include "Types.h"
#include "PolyChartViewFactory.h"
#include "PolyChartController.h"
#include "PolyChartRenderer.h"
#include "RenderingModule.h"
#include "RenderableFilters.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Data
        {
            class PolyChartModule : private Eegeo::NonCopyable
            
            {
            public:
                static PolyChartModule* Create(Modules::Core::RenderingModule& renderingModule);
                
                PolyChartModule(
                           Eegeo::Data::PolyChart::PolyChartController* pController,
                           Eegeo::Data::PolyChart::PolyChartViewFactory* pViewFactory,
                           Eegeo::Data::PolyChart::PolyChartRenderer* pRenderer,
                           Eegeo::Rendering::RenderableFilters& renderableFilters);
                
                ~PolyChartModule();
                
                Eegeo::Data::PolyChart::PolyChartController& GetController() { return *m_pController; }
                Eegeo::Data::PolyChart::PolyChartViewFactory& GetViewFactory() { return *m_pViewFactory; }
                Eegeo::Data::PolyChart::PolyChartRenderer& GetRenderer() { return *m_pRenderer; }
                
            private:
                Eegeo::Data::PolyChart::PolyChartController* m_pController;
                Eegeo::Data::PolyChart::PolyChartViewFactory* m_pViewFactory;
                Eegeo::Data::PolyChart::PolyChartRenderer* m_pRenderer;
                Eegeo::Rendering::RenderableFilters& m_renderableFilters;
            };
        }
    }
}