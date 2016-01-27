// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "POD.h"
#include <iostream>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            class PODMaterialParser
            {
            public:
                static PODMaterial* ParseMaterialFromPODStream(std::istream& stream, u32 fileOffset, u32 fileSize);
            };
        }
    }
}
