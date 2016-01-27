// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        MortonKey CreateMortonKeyFromVector(const std::vector<int> &elements);
    }
}
