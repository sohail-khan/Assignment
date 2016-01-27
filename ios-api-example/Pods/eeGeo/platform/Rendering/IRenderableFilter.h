// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief Interface to a filter of Renderable objects.
         *
         * This interface is used to notify renderable filter objects that it is time to add the renderables that need to be drawn to the RenderQueue.
         */
        class IRenderableFilter
        {
        public:
            virtual void EnqueueRenderables(const Rendering::RenderContext& renderContext, RenderQueue& renderQueue) = 0;
            virtual ~IRenderableFilter() { };
        };
    }
}