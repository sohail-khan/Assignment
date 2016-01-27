// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace LoadingScreenLayout
        {
            enum Values
            {
                FullScreen,
                Centred,
                CentredStretchToFit
            };
        }
        
        struct LoadingScreenConfig
        {
            LoadingScreenLayout::Values layout;
            v4 backgroundColor;
            v4 loadingBarColor;
            v4 loadingBarBackgroundColor;
            v2 loadingBarOffset;
            float screenWidth;
            float screenHeight;
            float fadeOutDurationSeconds;
            float timeoutSeconds;
            bool hasProgressBar;
            bool dismissAfterTimeout;
            
            LoadingScreenConfig()
            : layout(LoadingScreenLayout::FullScreen)
            , backgroundColor(v4::One())
            , loadingBarColor(v4::One())
            , loadingBarBackgroundColor(v4::Zero())
            , loadingBarOffset(0.5f, 0.1f)
            , screenWidth(0.0f)
            , screenHeight(0.0f)
            , fadeOutDurationSeconds(0.0f)
            , timeoutSeconds(0.0f)
            , hasProgressBar(true)
            , dismissAfterTimeout(false)
            {
            }
        };
    }
}