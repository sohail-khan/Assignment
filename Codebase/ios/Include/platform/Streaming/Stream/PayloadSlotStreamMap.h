// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "PayloadSlotStream.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        class PayloadSlotStreamMap
        {
        private:
            uint m_numOfPayloadSlots;
            std::vector<std::vector<PayloadSlotStream> > m_streamListsByDepth;
			
        public:
            PayloadSlotStreamMap();
            
            void addLodStreamMap(const LodStreamMap& lodStreamMap);
            
            void clearPayloadSlotStreamMappings();
            
            void streamsWithLastLODAtCell (const MortonKey& mortonKey, std::vector<PayloadSlotStream>& out_streamsToVisit);
            
            const std::vector<PayloadSlotStream> &streamsWithLODsAtDepth (int depth) const;
            
            int GetPayloadSlotForStream(IResourceStream* pStream) const;
            
            bool HasResourceStreamAtDepth(const PayloadSlotStream& payloadSlotStream, int depth, PayloadSlotStream& out_payloadStreamSlot);
        };
    }
}
