// Copyright (c) 2012-2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace DDS
        {
            struct DDSPixelFormat
            {
                u32 m_size;
                u32 m_flags;
                u32 m_fourCC;
                u32 m_rgbBitCount;
                u32 m_rBitMask;
                u32 m_gBitMask;
                u32 m_bBitMask;
                u32 m_aBitMask;
            };

            struct DDSHeader
            {
                u32           m_size;
                u32           m_flags;
                u32           m_height;
                u32           m_width;
                u32           m_pitchOrLinearSize;
                u32           m_depth;
                u32           m_mipMapCount;
                u32           m_reserved1[11];
                DDSPixelFormat	   m_pixelFormat;
                u32           m_caps;
                u32           m_caps2;
                u32           m_caps3;
                u32           m_caps4;
                u32           m_reserved2;
            };

            namespace DDSCaps2
            {
                enum Values
                {
                    Cubemap = 0x200,
                    CubemapPositiveX = 0x400,
                    CubemapNegativeX = 0x800,
                    CubemapPositiveY = 0x1000,
                    CubemapNegativeY = 0x2000,
                    CubemapPositiveZ = 0x4000,
                    CubemapNegativeZ = 0x8000,
                    Volume = 0x200000
                };
            }
        }
    }
}

#define Eegeo_MAKE_FOURCC(a, b, c, d)  (((u32)a) | (((u32)b) << 8) | (((u32)c) << 16) | (((u32)d) << 24 ))
