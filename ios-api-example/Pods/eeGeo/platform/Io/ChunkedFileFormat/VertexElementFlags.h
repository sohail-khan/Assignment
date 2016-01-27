// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace VertexElementFlags
            {
                // make sure this marries up with the compiler VertexElementFlags.
                // We should probably have a separate serialization value that is kept in sync.
                static const u16 POSITION = 1 << 0;
                static const u16 SHADOW_EXTRUSIONS = 1 << 1;
                static const u16 NORMAL = 1 << 2;
                static const u16 UV = 1 << 3;
                static const u16 LIGHTDOTS = 1 << 4;
                static const u16 UV2 = 1 << 5;
                static const u16 COLOR = 1 << 6;
                                
                static const u16 POSITION_NORMAL = (POSITION | NORMAL);
                static const u16 POSITION_NORMAL_UV = (POSITION | NORMAL | UV);
                static const u16 POSITION_NORMAL_UV_COLOR = (POSITION | NORMAL | UV | COLOR);
                static const u16 POSITION_UV_LIGHTDOTS = (POSITION | UV | LIGHTDOTS);
                static const u16 POSITION_SHADOW_EXTRUSIONS = (POSITION | SHADOW_EXTRUSIONS);
                static const u16 POSITION_UV_LIGHTDOTS_COLOR = (POSITION | UV | LIGHTDOTS | COLOR);
                
            }
        }
    }
}
