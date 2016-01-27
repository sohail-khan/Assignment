// Copyright (c) 2012-2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "JpegType.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace Jpeg
        {
            struct JpegImage
            {
                int width;
                int height;
                int components;
                JpegType::Values colour_space;
                Byte* pixels;
                
                int byte_count()
                {
                    return width * height * components;
                }
            };
        }
    }
}