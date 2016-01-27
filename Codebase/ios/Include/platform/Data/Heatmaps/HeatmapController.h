//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "HeatmapModel.h"
#include "HeatmapView.h"
#include "HeatmapViewFactory.h"
#include "HeatmapRenderer.h"
#include "DataEntityController.h"

namespace Eegeo
{
    namespace Data
    {
        namespace Heatmaps
        {
            struct HeatmapArgs
            {
                typedef THeatmapId TId;
                typedef HeatmapModel TModel;
                typedef HeatmapView TView;
                typedef HeatmapViewFactory TViewFactory;
                typedef HeatmapRenderer TRenderableFilter;
            };
            
            class HeatmapController : public Data::DataEntityController<HeatmapArgs>
            {
            public:
                HeatmapController(HeatmapViewFactory& viewFactory, HeatmapRenderer& renderableFilter)
                : DataEntityController(viewFactory, renderableFilter)
                {
                }
                
            };
        }
    }
}