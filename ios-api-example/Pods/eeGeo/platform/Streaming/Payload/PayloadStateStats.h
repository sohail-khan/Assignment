// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Payload.h"

namespace Eegeo
{
    namespace Streaming
    {
        class PayloadStateStats
        {
        public:
            PayloadStateStats();
            void IncrementCountForState(PayloadState::PayloadStateValues state);
            int GetCountForState(PayloadState::PayloadStateValues state) const;
            
        private:
            int m_stateCounts[Eegeo::PayloadState::MAX];
        };
    }
};
