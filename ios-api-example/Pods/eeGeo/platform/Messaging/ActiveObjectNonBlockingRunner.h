// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IRunnable.h"
#include "Types.h"
#include "ActiveObject.h"

namespace Eegeo
{
    namespace Messaging
    {
        template <typename TMessage, typename TDispatcher>
        class ActiveObjectNonBlockingRunner : protected Eegeo::NonCopyable, public Concurrency::IRunnable
        {
        public:
            ActiveObjectNonBlockingRunner(ActiveObject<TMessage, TDispatcher>& activeObject)
            : m_activeObject(activeObject)
            {
            }
            
            bool operator()()
            {
                return m_activeObject.ProcessAllAvailableMessages();
            }
            
            void OnStarted()
            {
                m_activeObject.OnStarted();
            }
            
            void OnStopped()
            {
                m_activeObject.OnStopped();
            }
            
        private:
            ActiveObject<TMessage, TDispatcher>& m_activeObject;
        };
    }
}


