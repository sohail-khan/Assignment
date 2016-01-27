// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "MPMCQueue.h"

namespace Eegeo
{
	namespace Concurrency
	{
        template <typename T>
        MPMCQueue<T>::MPMCQueue()
        {
            pthread_mutex_init(&m_mutex, 0);
        }
        
        template <typename T>
        MPMCQueue<T>::~MPMCQueue()
        {
            pthread_mutex_destroy(&m_mutex);
        }
        
        template <typename T>
        size_t MPMCQueue<T>::Size() const
        {
            size_t size = 0;
            pthread_mutex_lock(&m_mutex);
            size = m_queue.size();
            pthread_mutex_unlock(&m_mutex);
            return size;
        }
        
        template <typename T>
        void MPMCQueue<T>::Enqueue(T message)
        {
            pthread_mutex_lock(&m_mutex);
            m_queue.push_back(message);
            pthread_mutex_unlock(&m_mutex);
            m_signal.Signal();
        }
        
        template <typename T>
        void MPMCQueue<T>::EnqueueHead(T message)
        {
            pthread_mutex_lock(&m_mutex);
            m_queue.push_front(message);
            pthread_mutex_unlock(&m_mutex);
            m_signal.Signal();
        }

        template <typename T>
        T MPMCQueue<T>::Dequeue()
        {
            m_signal.Wait();
            return DequeueMessageFromHead();
        }
        
        template <typename T>
        bool MPMCQueue<T>::TryDequeue(T& message)
        {
            if (m_signal.TryWait())
            {
                message = DequeueMessageFromHead();
                return true;
            }
            return false;
        }
        
        template <typename T>
        T MPMCQueue<T>::DequeueMessageFromHead()
        {
            pthread_mutex_lock(&m_mutex);
            Eegeo_ASSERT(m_queue.size() > 0, "No message to deqeue");
            T message = m_queue.front();
            m_queue.pop_front();
            pthread_mutex_unlock(&m_mutex);
            return message;
        }
	}
}