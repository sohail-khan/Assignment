//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "PolyChartModel.h"

namespace Eegeo
{
    namespace Data
    {
        namespace PolyChart
        {
            class PolyChartView : private Eegeo::NonCopyable
            {
            public:
                PolyChartView(PolyChartModel& model, Rendering::Renderables::WorldMeshRenderable* pRenderable);
                void Update();
                
                PolyChartModel& GetModel() const;
                Rendering::Renderables::WorldMeshRenderable* GetRenderable();
            private:
                PolyChartModel& m_model;
                Rendering::Renderables::WorldMeshRenderable* m_pRenderable;
            };
        }
    }
}