// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#ifdef EEGEO_IOS
	#include <libkern/OSAtomic.h>
#elif defined EEGEO_DROID || defined(EEGEO_OSX) || defined(EEGEO_WIN)
	#include <pthread.h>
#endif

namespace Eegeo
{
	class SpinLock
	{
#ifdef EEGEO_IOS
		OSSpinLock 		m_lock;
#elif defined(EEGEO_DROID) || defined(EEGEO_OSX) || defined(EEGEO_WIN)
		pthread_mutex_t m_lock;
#endif

	public:

#ifdef EEGEO_IOS
		SpinLock		()	{ m_lock = OS_SPINLOCK_INIT; }
		~SpinLock		()	{}
#elif defined EEGEO_DROID || defined(EEGEO_OSX) || defined(EEGEO_WIN)
		SpinLock		()	{ pthread_mutex_init(&m_lock, 0); }
		~SpinLock		()	{ pthread_mutex_destroy(&m_lock); }
#endif
		void	Lock	();
		void	Unlock	();
	};
	
	class SpinLockAutoLock
	{
		SpinLock& 		m_spinLock;
	public:
		SpinLockAutoLock( SpinLock& lock ) : m_spinLock(lock)
		{
			m_spinLock.Lock();
		}
		
		~SpinLockAutoLock()
		{
			m_spinLock.Unlock();
		}
	};
}

#ifdef EEGEO_IOS
	inline void Eegeo::SpinLock::Lock()
	{
		OSSpinLockLock(&m_lock);
	}

	inline void Eegeo::SpinLock::Unlock()
	{
		OSSpinLockUnlock(&m_lock);
	}
#elif defined EEGEO_DROID || defined(EEGEO_OSX) || defined(EEGEO_WIN)
    inline void Eegeo::SpinLock::Lock()
	{
		pthread_mutex_lock(&m_lock);
	}

	inline void Eegeo::SpinLock::Unlock()
	{
		pthread_mutex_unlock(&m_lock);
	}
#endif
