//  Copyright (c) 2015 eeGeo. All rights reserved.
#pragma once

#include "Types.h"
#include "BlockCoverageTrees.h"
#include <iosfwd>
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        namespace BlockCoverageTrees
        {
            class BlockCoverageTreeFactory: protected Eegeo::NonCopyable
            {
            public:
                static BlockCoverageTree* LoadBlockCoverageTreeFromStream(std::istream& stream);
                
                static BlockCoverageTree* LoadBlockCoverageTreeFromBlocks(const std::vector<u64>& buffer);
            };
        }
    }
}