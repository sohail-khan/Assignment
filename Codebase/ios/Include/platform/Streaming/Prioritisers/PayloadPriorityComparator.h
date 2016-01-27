// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"

namespace Eegeo
{
    namespace Streaming
    {
        class PayloadPriorityComparator
        {
        public:
            bool PayloadAIsPrioritisedOverB(Payload *pPayloadA, Payload *pPayloadB);
            bool operator() (Payload *pPayloadA, Payload *pPayloadB) { return PayloadAIsPrioritisedOverB(pPayloadA, pPayloadB);}
        };
    }
    
}
