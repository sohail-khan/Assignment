// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Helpers.h"
#include "MortonKey.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        namespace MortonKeyLongLoader
        {                     
            void LoadFromTextFile(Helpers::IFileIO& fileIO, const char* filename, std::vector<MortonKey> &keys);
        }
    }
}
