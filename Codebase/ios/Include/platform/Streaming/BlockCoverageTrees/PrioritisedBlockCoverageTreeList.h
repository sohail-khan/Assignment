//  Copyright (c) 2015 eeGeo. All rights reserved.
#pragma once

#include "Streaming.h"
#include "BlockCoverageTree.h"
#include "CoverageTreeMinMaxLevel.h"
#include <vector>


namespace Eegeo
{
    namespace Streaming
    {
        namespace BlockCoverageTrees
        {
            struct StoreCoverageEntry
            {
                BlockCoverageTree* coverageTree;
                ResourceStreamComponent* resourceStreamComponent;
                
                StoreCoverageEntry(BlockCoverageTree* tree, ResourceStreamComponent* stream)
                : coverageTree(tree)
                , resourceStreamComponent(stream) {}
            };

            class PrioritisedBlockCoverageTreeList: protected Eegeo::NonCopyable
            {
            public:
                PrioritisedBlockCoverageTreeList();
                
                ~PrioritisedBlockCoverageTreeList();
                
                bool HasCoverageFor(const MortonKey& mortonKey, ResourceStreamComponent*& out_resourceStream) const;
                
                bool HasCoverageFor(const MortonKey& mortonKey) const;
                
                void InsertCoverageTree(BlockCoverageTrees::BlockCoverageTree* coverageTree, ResourceStreamComponent* stream);
                
                const CoverageTrees::CoverageTreeMinMaxLevel GetCoverageTreeMinMaxLevels() const;
                
                const bool IsEmpty() const;
                
            private:
                
                int m_lowestLevel;
                int m_highestLevel;
                
                std::vector<StoreCoverageEntry> m_storeCoverageEntries;
            };
        }
    }
}