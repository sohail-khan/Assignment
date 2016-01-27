// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRunnable.h"
#include <pthread.h>

namespace Eegeo
{
    namespace Concurrency
    {
        class Thread : protected Eegeo::NonCopyable
        {
        public:
            Thread(IRunnable& runnable);
            virtual ~Thread();

            bool Start();
            void WaitForStop();
            bool IsRunning() const;

        private:
            IRunnable& m_runnable;
            pthread_t m_thread;
            bool m_isRunning;
            static void* Run(void* pObj);

            IRunnable& GetRunnable() const;
        };
    }
}
