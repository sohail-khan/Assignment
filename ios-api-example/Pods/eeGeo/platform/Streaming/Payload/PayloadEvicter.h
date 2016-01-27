// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Streaming
	{		
        class PayloadEvicter : protected Eegeo::NonCopyable
        {
        private:
            QuadTreeCube *m_pQuadTreeCube;
            PayloadPool *m_pPayloadPool;
            
            int m_numOfPlaceholderPayloadsEvicted;
            int m_totalPlaceholderPayloadsEvicted;
            
            int m_numOfLatePayloadsEvicted;
            int m_totalLatePayloadsEvicted;
            
        public:
            int NumOfPlaceholderPayloadsEvicted() { return m_numOfPlaceholderPayloadsEvicted; }
            int TotalPlaceholderPayloadsEvicted() { return m_totalPlaceholderPayloadsEvicted; }
            
            int NumOfLatePayloadsEvicted() { return m_numOfLatePayloadsEvicted; }
            int TotalLatePayloadsEvicted() { return m_totalLatePayloadsEvicted; }
            
            PayloadEvicter(QuadTreeCube *pQuadTreeCube,
                           PayloadPool *pPayloadPool):
            m_pQuadTreeCube(pQuadTreeCube), 
            m_pPayloadPool(pPayloadPool),
            m_numOfPlaceholderPayloadsEvicted(0), 
            m_totalPlaceholderPayloadsEvicted(0), 
            m_numOfLatePayloadsEvicted(0), 
            m_totalLatePayloadsEvicted(0)
            {}
            
            void EvictPayloads(int updateCount);
            void EvictAllPayloads();
            
        private:
            uint EvictPayloads(QuadTreeNode *pNode, uint visibleSlotsAbove, int updateCount);
            void EvictAllPayloads(QuadTreeNode *pNode);
        };
    }    
}