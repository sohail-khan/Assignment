// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRenderableFilter.h"
#include "PlaceNames.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNamesViewFilter : protected Eegeo::NonCopyable, public Rendering::IRenderableFilter
            {
            public:
                PlaceNamesViewFilter(const PlaceNamesController& placeNamesController);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
                
                void SetEnabled(bool enabled);
                
            private:
                const PlaceNamesController& m_placeNamesController;
                bool m_enabled;
            };
        }
    }
}
