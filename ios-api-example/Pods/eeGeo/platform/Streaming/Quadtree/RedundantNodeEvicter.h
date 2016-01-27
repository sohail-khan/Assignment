// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
	{
        class RedundantNodeEvicter : protected Eegeo::NonCopyable
        {
        private:
			QuadTreeNodePool *p_mNodePool;            
            int m_numOfNodesEvicted;
            int m_totalNodesEvicted;
            
        public:
            int numOfNodesEvicted() { return m_numOfNodesEvicted; }
            int totalNodesEvicted() { return m_totalNodesEvicted; }
            
            RedundantNodeEvicter(QuadTreeNodePool *pNodePool)
            :p_mNodePool(pNodePool),
            m_numOfNodesEvicted(0),
            m_totalNodesEvicted(0)
            {
            }
            
            void evictEmptyLeafNodes(int updateCount, std::vector<MortonKey>& keysThatAreNoLongerVisible);
            void evictAllNodes();
        };
    }
}