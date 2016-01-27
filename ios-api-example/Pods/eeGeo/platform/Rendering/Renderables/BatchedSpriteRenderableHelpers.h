// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "IdTypes.h"
#include "Bounds.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            Eegeo::Geometry::Bounds2D CalculateUvBoundsForSpriteTileIndex(int tileIndex, int tileCountHorizontal, int tileCountVertical);
        }
    }
}
