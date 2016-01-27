// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Collision.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Collision
    {
        namespace CollisionGroup
        {
            enum Type
            {
                Default =   0x00,
                Terrain =   0x01,
                Buildings = 0x02,
                Trees =     0x04,
                Roads =     0x08,
                Rail =      0x10,
                Tramlines = 0x20,
                Interiors = 0x40,
                Highlights= 0x80
            };
            
            const u32 CollideNone = 0;
            const u32 CollideAll = 0xffffffff;
        }
    }
}
