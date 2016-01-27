// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"

namespace Eegeo
{    
    namespace Streaming
    {
        struct PayloadSlotStream
        {
            IResourceStream *pStream;
            uint payloadSlotIndex;
            
            PayloadSlotStream(IResourceStream *pStream, uint payloadSlotIndex):
                pStream(pStream),
                payloadSlotIndex(payloadSlotIndex)
            {
            }
        };
	}
}