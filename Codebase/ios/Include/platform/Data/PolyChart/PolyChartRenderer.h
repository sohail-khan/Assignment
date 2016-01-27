//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "SimpleRenderFilter.h"
#include "PolyChartView.h"

namespace Eegeo
{
    namespace Data
    {
        namespace PolyChart
        {
            class PolyChartRenderer : public Rendering::Filters::SimpleRenderFilter<PolyChartView>
            {
            };
        }
    }
}