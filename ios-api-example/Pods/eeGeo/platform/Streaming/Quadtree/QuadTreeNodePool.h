// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "Pool.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming 
    {
        class QuadTreeNodePool : protected Eegeo::NonCopyable
        {
        public:
            static const int POOL_SIZE = 1780;
            
        private:
            QuadTreeNodePoolItemFactory *m_pFactory;
            DataStructures::Pool<QuadTreeNode*> *m_pNodePool;
            
        public:
            int GetCount() { return m_pNodePool->GetCount(); }
            int GetCapacity() { return m_pNodePool->GetCapacity(); }
            const std::vector<DataStructures::PoolEntry<QuadTreeNode*> >& GetEntries() { return m_pNodePool->GetEntries(); }
            
            QuadTreeNodePool();
            ~QuadTreeNodePool();
            
            QuadTreeNode* allocateNode();
            
            void releaseNode(QuadTreeNode *node);
        };
    }
}
