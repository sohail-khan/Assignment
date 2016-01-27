// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace Debug
    {
        class IMemoryStats
        {
        public:
            virtual ~IMemoryStats() {};
            virtual size_t MemoryUsed() const = 0;
            virtual size_t VirtualMemoryUsed() const = 0;
            virtual size_t FreeMemory() const = 0;
        };
    }
}
