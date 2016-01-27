// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#ifdef EEGEO_IOS
#include <libkern/OSAtomic.h>
#elif defined(EEGEO_WIN)
#include "EegeoWindowsGuard.h"
#endif

namespace Eegeo
{
    namespace Concurrency
    {
        inline bool AtomicCompareAndSwap32(s32 oldValue, s32 newValue, volatile s32* theValue)
        {
#ifdef EEGEO_IOS
            return OSAtomicCompareAndSwap32Barrier((int32_t)oldValue, (int32_t)newValue, (volatile int32_t*)theValue);
#elif defined EEGEO_DROID || defined(EEGEO_OSX)
            return __sync_bool_compare_and_swap(theValue, oldValue, newValue);
#elif defined EEGEO_WIN
			return InterlockedCompareExchange((volatile long*)theValue, (long)newValue, (long)oldValue) == oldValue;
#endif
        }
    }
}


