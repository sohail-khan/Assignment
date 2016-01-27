// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMessageQueue.h"
#include "MPMCQueue.h"
#include "Types.h"

namespace Eegeo
{
    namespace Messaging
    {
        template <typename T>
        class MessageQueue : protected Eegeo::NonCopyable, public IMessageQueue<T>
        {
        public:
            void Enqueue(T const message) { m_queue.Enqueue(message); }
            void EnqueueHead(T const message) { m_queue.EnqueueHead(message); }
            T Dequeue() { return m_queue.Dequeue(); }
            bool TryDequeue(T& out_message) { return m_queue.TryDequeue(out_message); }

        private:
            Eegeo::Concurrency::MPMCQueue<T> m_queue;
        };
    }
}
