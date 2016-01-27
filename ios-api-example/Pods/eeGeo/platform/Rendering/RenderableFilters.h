// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include <vector>
#include "IRenderableFilter.h"

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief A set of renderable filters that can be called upon to add visible renderables to the RenderQueue.
         */
        class RenderableFilters : public IRenderableFilter
        {
        public:
            void AddRenderableFilter(IRenderableFilter& filterToAdd);
            void RemoveRenderableFilter(IRenderableFilter& filterToRemove);
            void EnqueueRenderables(const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
        private:
            typedef std::vector<IRenderableFilter*> TFilters;
            TFilters m_filters;
        };
    }
}
