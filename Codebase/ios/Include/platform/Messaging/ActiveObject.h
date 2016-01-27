// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IRunnable.h"
#include "MessageQueue.h"
#include "Types.h"

namespace Eegeo
{
    namespace Messaging
    {
        template <typename TMessage, typename TDispatcher>
        class ActiveObject : public TDispatcher, protected Eegeo::NonCopyable
        {
        public:
        	ActiveObject()
        	: m_messageQueue(MessageQueue<TMessage>())
        	{
        	}

        	ActiveObject(MessageQueue<TMessage>& messageQueue)
        	: m_messageQueue(messageQueue)
        	{
        	}

            virtual ~ActiveObject() { }

            void SendMessage(TMessage message)
            {
                m_messageQueue.Enqueue(message);
            }
            
            bool ProcessAllAvailableMessages()
            {
                TMessage message;
                
                OnBeforeMessagesHandled();
                
                while(m_messageQueue.TryDequeue(message))
                {
                    bool continueRunning = ProcessMessage(message);
                    if(!continueRunning)
                    {
                        return false;
                    }
                }
                return true;
            }
            
            bool WaitAndProcessSingleMessage()
            {
                TMessage message = m_messageQueue.Dequeue();
                bool continueRunning = ProcessMessage(message);
                return continueRunning;
            }

            virtual void OnMessageHandled(TMessage message) { }
            virtual void OnBeforeMessagesHandled() { }
            virtual void OnAllMessagesHandled() { }
            virtual void OnStarted() { }
            virtual void OnStopped() { }
            
        private:
            MessageQueue<TMessage>& m_messageQueue;
            
            bool ProcessMessage(TMessage message)
            {
                bool continueRunning = message->Handle(*this);
                OnMessageHandled(message);
                return continueRunning;
            }
        };
    }
}
