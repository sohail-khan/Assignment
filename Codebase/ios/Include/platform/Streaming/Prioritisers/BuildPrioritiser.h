// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo 
{
    namespace Streaming
    {
        class BuildPrioritiser : protected Eegeo::NonCopyable
        {	
        private:
            PayloadPool *m_pPayloadPool;
            PayloadPriorityComparator *m_pPayloadComparator;

        public:
            BuildPrioritiser(PayloadPool *pPayloadPool,
                             PayloadPriorityComparator *pPayloadComparator)
            :m_pPayloadPool(pPayloadPool),
            m_pPayloadComparator(pPayloadComparator)
            { }
            
            Payload* FindNextPayloadToBuild(int updateCount);
            
            void GetPrioritisedPayloads(int updateCount, int maxPayloadCount, std::vector<Payload*>& prioritisedPayloads);
        };
    }
}