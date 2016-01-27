// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMemoryStats.h"

namespace Eegeo
{
    namespace Android
    {
        class AndroidMemoryStats : public Debug::IMemoryStats
        {
        public:
        	AndroidMemoryStats() { }
        	virtual ~AndroidMemoryStats() { }
        	size_t MemoryUsed() const;
        	size_t VirtualMemoryUsed() const;
        	size_t FreeMemory() const;
        };
    }
}
