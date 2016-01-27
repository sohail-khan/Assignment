// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Messaging
    {
        template<typename M>
        class IMessageQueue
        {
        public:
            virtual ~IMessageQueue() {};
            virtual void Enqueue(M const message) = 0;
            virtual bool TryDequeue(M& out_message) = 0;
        };
    }
}
