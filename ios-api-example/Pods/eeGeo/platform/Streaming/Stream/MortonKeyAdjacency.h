// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MortonKey.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        void ExpandToIncludeAdjacentKeys(
                const MortonKey& key,
                std::vector<MortonKey>& out_adjacentKeysIncludingInputKey);
        
        void GetNonDiagonalAdjacentKeys(const MortonKey& key, std::vector<MortonKey>& out_adjacentKeys);
        
        MortonKey GetTopNeighbour(const MortonKey& key);
        MortonKey GetRightNeighbour(const MortonKey& key);
        MortonKey GetBottomNeighbour(const MortonKey& key);
        MortonKey GetLeftNeighbour(const MortonKey& key);
    }
}