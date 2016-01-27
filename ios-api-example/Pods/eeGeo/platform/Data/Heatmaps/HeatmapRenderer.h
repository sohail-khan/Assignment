//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "IRenderableFilter.h"
#include "Rendering.h"
#include "Heatmaps.h"
#include "HeatmapView.h"
#include "SimpleRenderFilter.h"
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace Heatmaps
        {
            class HeatmapRenderer : public Rendering::Filters::SimpleRenderFilter<HeatmapView>
            {
            };
        }
    }
}