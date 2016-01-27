//  Copyright (c) 2015 eeGeo. All rights reserved.
#pragma once

#include "BlockCoverageTrees.h"
#include "CoverageTreeMinMaxLevel.h"
#include "Streaming.h"
#include "Types.h"

#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        namespace BlockCoverageTrees
        {
            class BlockCoverageTree: protected Eegeo::NonCopyable
            {
            public:
                BlockCoverageTree();
                ~BlockCoverageTree();
                
                bool HasCoverageFor(const MortonKey& mortonKey, const int level) const;
 
                void AddBlockCoverageTreeForLevelFace(int level, int face, const std::vector<u64>& blocks);
                
                const CoverageTrees::CoverageTreeMinMaxLevel GetCoverageTreeMinMaxLevels() const;
                
                const bool IsEmpty() const;
                
            private:
                static const int MaxLevel = 15;
                
                int m_lowestLevel;
                int m_highestLevel;

                BlockCoverageTreeCube* GetOrCreateTreeRootForLevel(int level);
                BlockCoverageTreeCube* m_treeRootsByLevel[MaxLevel + 1];
            };
        }
    }
}