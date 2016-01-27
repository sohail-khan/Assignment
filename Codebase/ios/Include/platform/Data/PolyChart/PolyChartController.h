//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "PolyChartModel.h"
#include "PolyChartView.h"
#include "PolyChartRenderer.h"
#include "PolyChartViewFactory.h"
#include "DataEntityController.h"

namespace Eegeo
{
    namespace Data
    {
        namespace PolyChart
        {
            struct PolyChartArgs
            {
                typedef TPolyChartId TId;
                typedef PolyChartModel TModel;
                typedef PolyChartView TView;
                typedef PolyChartViewFactory TViewFactory;
                typedef PolyChartRenderer TRenderableFilter;
            };
            
            class PolyChartController : public DataEntityController<PolyChartArgs>
            {
            public:
                PolyChartController(PolyChartViewFactory& viewFactory, PolyChartRenderer& renderableFilter)
                : DataEntityController(viewFactory, renderableFilter)
                {
                }
            };
        }
    }
}