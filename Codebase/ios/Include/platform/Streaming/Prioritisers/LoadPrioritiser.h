// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
	{
        class LoadPrioritiser : protected Eegeo::NonCopyable
        {	
        private:
            PayloadPool *m_pPayloadPool;
            PayloadPriorityComparator *m_pPayloadComparator;
            PayloadSortFunctor *m_pPayloadSortFunctor;
            
        public:
            LoadPrioritiser(PayloadPool *pPayloadPool, PayloadPriorityComparator *pPayloadComparator);
            ~LoadPrioritiser();

            void PayloadsToLoadInPriorityOrder(int updateCount, std::vector<Payload*>& outPayloadsToLoadInPriorityOrder);
        };
    }
}
