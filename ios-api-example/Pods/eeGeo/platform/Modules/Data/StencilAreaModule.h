//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "StencilAreaViewFactory.h"
#include "StencilAreaController.h"
#include "StencilAreaRenderer.h"
#include "RenderingModule.h"
#include "RenderableFilters.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Data
        {
            class StencilAreaModule : private Eegeo::NonCopyable
            
            {
            public:
                static StencilAreaModule* Create(Modules::Core::RenderingModule& renderingModule);
                
                StencilAreaModule(
                                Eegeo::Data::StencilArea::StencilAreaController* pController,
                                Eegeo::Data::StencilArea::StencilAreaViewFactory* pViewFactory,
                                Eegeo::Data::StencilArea::StencilAreaRenderer* pRenderer,
                                Eegeo::Rendering::RenderableFilters& renderableFilters);
                
                ~StencilAreaModule();
                
                Eegeo::Data::StencilArea::StencilAreaController& GetController() { return *m_pController; }
                Eegeo::Data::StencilArea::StencilAreaViewFactory& GetViewFactory() { return *m_pViewFactory; }
                Eegeo::Data::StencilArea::StencilAreaRenderer& GetRenderer() { return *m_pRenderer; }
                
            private:
                Eegeo::Data::StencilArea::StencilAreaController* m_pController;
                Eegeo::Data::StencilArea::StencilAreaViewFactory* m_pViewFactory;
                Eegeo::Data::StencilArea::StencilAreaRenderer* m_pRenderer;
                Eegeo::Rendering::RenderableFilters& m_renderableFilters;
            };
        }
    }
}