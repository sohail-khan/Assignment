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
            class PODScene;
            
            class PODSceneParser
            {
            public:
                static PODScene* ParseSceneFromPODStream(std::istream& stream, u32 fileOffset, u32 fileSize);
            };
            
        }
    }
}
