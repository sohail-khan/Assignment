// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "POD.h"
#include "Types.h"
#include <iostream>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            class PODTextureParser
            {
            public:
                static PODTexture* ParseTextureFromPODStream(std::istream& stream, u32 fileOffset, u32 fileSize);
            };
        }
    }
}
