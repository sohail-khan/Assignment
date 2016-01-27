// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Streaming
	{
        class SceneGraphUpdater : protected Eegeo::NonCopyable
        {
        private:            
            QuadTreeCube *m_pQuadTreeCube;
            PayloadPool *m_pPayloadPool;
            
        private:
            int m_numOfPayloadsInserted;
            int m_totalPayloadsInserted;            
            int m_numOfChildPayloadsEvicted;
            int m_totalChildPayloadsEvicted;
            
        public:
            int numOfPayloadsInserted() { return m_numOfPayloadsInserted; }		
            int totalPayloadsInserted() { return m_totalPayloadsInserted; }
            int numOfChildPayloadsEvicted() { return m_numOfChildPayloadsEvicted; }		
            int totalChildPayloadsEvicted() { return m_totalChildPayloadsEvicted; }				
            
            SceneGraphUpdater(QuadTreeCube *pQuadTreeCube,
                           PayloadPool *pPayloadPool):
            m_pQuadTreeCube(pQuadTreeCube), 
            m_pPayloadPool(pPayloadPool),
            m_numOfPayloadsInserted(0), 
            m_totalPayloadsInserted(0), 
            m_numOfChildPayloadsEvicted(0), 
            m_totalChildPayloadsEvicted(0)
            {}
            
            void insertBuiltPayloads(int updateCount);
            
            
        private:            
            void insertBuiltPayloads(QuadTreeNode *pNode, u32 slotsToVisit, u32 slotsToEvict, int updateCount);
        };
    }
}