// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRenderableFilter.h"
#include "Rendering.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Filters
        {
            class RenderableRepository : protected Eegeo::NonCopyable, public IRenderableFilter
            {
            public:
                RenderableRepository();
                void AddRenderable(RenderableBase* pRenderable);
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
                
            private:
                typedef std::vector<RenderableBase*> TRenderables;
                TRenderables m_renderables;
            };
        }
    }
}
