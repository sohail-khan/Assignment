//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Heatmaps.h"
#include "HeatmapRenderable.h"

namespace Eegeo
{
    namespace Data
    {
        namespace Heatmaps
        {
            class HeatmapView : private Eegeo::NonCopyable
            {
            public:
                HeatmapView(HeatmapModel& model, HeatmapRenderable* pRenderable);
                void Update();
                
                HeatmapModel& GetModel();
                HeatmapRenderable* GetRenderable();
                
            private:
                HeatmapModel& m_model;
                HeatmapRenderable* m_pRenderable;
            };
        }
    }
}