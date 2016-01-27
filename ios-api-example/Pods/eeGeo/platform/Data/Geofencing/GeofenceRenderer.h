// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "IRenderableFilter.h"
#include "Rendering.h"
#include "Geofencing.h"
#include "SimpleRenderFilter.h"
#include "GeofenceView.h"
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace Geofencing
        {
            class GeofenceRenderer : public Rendering::Filters::SimpleRenderFilter<GeofenceView>
            {
            };
        }
    }
}


