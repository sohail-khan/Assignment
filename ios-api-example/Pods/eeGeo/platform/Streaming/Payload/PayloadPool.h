// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "Pool.h"
#include "SummaryStats.h"
#include "Payload.h"

namespace Eegeo
{
    namespace Streaming 
    {
        class PayloadPoolItemFactory;
        
        class PayloadPool : protected Eegeo::NonCopyable
        {   
        public:
            static const int POOL_SIZE = 1780;
            
        private:
            PayloadPoolItemFactory *m_pFactory;
            DataStructures::Pool<Payload*> *m_pPayloadPool;
            Eegeo::Debug::SummaryStats m_stateTimeStats[PayloadState::MAX][2];
            
            void updateStateTimeStats(Payload* payload);
                        
        public:
            int GetCount() const;
            int GetCapacity() const;
            const std::vector<DataStructures::PoolEntry<Payload*> >& GetEntries();
            
            PayloadPool();            
            ~PayloadPool();                        
            Payload* allocatePayload();            
            void ReleasePayload(Payload* payload);
            
            void ResetStats();
            const Eegeo::Debug::SummaryStats& stateTimeStats(PayloadState::PayloadStateValues state, bool forCached) const;
        };
    }
}