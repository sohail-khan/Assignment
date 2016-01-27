// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace Fonts
    {
        namespace BMFont
        {
            struct BMFontKerning
            {
                u32 first;
                u32 second;
                int amount;
                
                BMFontKerning()
                : first(0), second(0), amount(0)
                {
                }
            };
            
        }
    }
}
