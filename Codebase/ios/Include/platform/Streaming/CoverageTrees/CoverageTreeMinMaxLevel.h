//  Copyright (c) 2015 eeGeo. All rights reserved.


#pragma once
#include "MortonKey.h"


namespace Eegeo
{
    namespace Streaming
    {
        namespace CoverageTrees
        {
            struct CoverageTreeMinMaxLevel
            {
                int min;
                int max;
                CoverageTreeMinMaxLevel(int min, int max): min(min), max(max){}
            };
        }
    }
}
