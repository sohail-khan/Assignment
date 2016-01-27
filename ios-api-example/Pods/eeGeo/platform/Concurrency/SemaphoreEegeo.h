// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <iostream>
#include "Types.h"

#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
#include <dispatch/dispatch.h>
#elif defined(EEGEO_DROID) || defined(EEGEO_WIN)
#include <semaphore.h>
#endif

namespace Eegeo
{
    namespace Concurrency
    {
        class Semaphore : protected Eegeo::NonCopyable
        {
        public:
            Semaphore();
            ~Semaphore();
            
            void Wait();
            bool TryWait();
            void Signal();
        private:
#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
            dispatch_semaphore_t m_semaphore;
#elif defined(EEGEO_DROID) || defined(EEGEO_WIN)
            sem_t m_semaphore;
#endif
        };
    }
}

