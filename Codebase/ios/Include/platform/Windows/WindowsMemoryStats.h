// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMemoryStats.h"

namespace Eegeo
{
    namespace Windows
    {
        class WindowsMemoryStats : public Debug::IMemoryStats
        {
        public:
			WindowsMemoryStats() { }
        	virtual ~WindowsMemoryStats() { }
        	size_t MemoryUsed() const;
        	size_t VirtualMemoryUsed() const;
        	size_t FreeMemory() const;
        };
    }
}
