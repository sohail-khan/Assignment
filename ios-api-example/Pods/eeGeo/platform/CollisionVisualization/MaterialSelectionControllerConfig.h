// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace CollisionVisualization
    {
        struct MaterialSelectionControllerConfig
        {
            v4 Color;
            float FlashFrequency;
            float FlashSaturateScale;
            float FlashAlphaMin;
            float FlashAlphaMax;
            
            MaterialSelectionControllerConfig()
            : Color(v4::Zero())
            , FlashFrequency(0.f)
            , FlashSaturateScale(0.f)
            , FlashAlphaMin(0.f)
            , FlashAlphaMax(0.f)
            {}
        };
    }
}