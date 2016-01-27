// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "SemaphoreEegeo.h"
#include <pthread.h>
#include <queue>
#include <list>

namespace Eegeo
{
	namespace Concurrency
	{
        template<typename T>
        class MPMCQueue : protected Eegeo::NonCopyable
        {
            public:
               MPMCQueue();
               ~MPMCQueue();

               size_t Size() const;
               void Enqueue(T message);
               void EnqueueHead(T message);
               T Dequeue();
               bool TryDequeue(T& message);
            private:
               T DequeueMessageFromHead();
               std::list<T> m_queue;
               pthread_mutex_t m_mutex;
               Semaphore m_signal;
        };
        
	}
}

#include "MPMCQueueImpl.h"


