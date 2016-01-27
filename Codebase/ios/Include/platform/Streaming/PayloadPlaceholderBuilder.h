// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"

namespace Eegeo
{
    namespace Streaming
    {
        class PayloadPlaceholderBuilder : protected Eegeo::NonCopyable
        {
           public:
               PayloadPlaceholderBuilder(PayloadPool* pPayloadPool) :
                   m_pPayloadPool(pPayloadPool)
               {
               };
            
               void BuildPlaceholders();
            
           private:
               PayloadPool* m_pPayloadPool;
        };
    }
}
