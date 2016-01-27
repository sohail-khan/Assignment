// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CollisionVisualization.h"
#include "VectorMath.h"

#include <vector>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        v4 CalculateFlashingColor(float phase, const v4& baseColor, float minAlpha, float maxAlpha, float oversaturateScale);
        v3 CalculateCentroid(const std::vector<v3>& points);
    }
}