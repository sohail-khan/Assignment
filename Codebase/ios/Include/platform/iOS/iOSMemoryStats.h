// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMemoryStats.h"

namespace Eegeo
{
    namespace iOS
    {
        class iOSMemoryStats : public Debug::IMemoryStats
        {
        public:
            iOSMemoryStats() { };
            ~iOSMemoryStats() { };
            virtual size_t MemoryUsed() const;
            virtual size_t VirtualMemoryUsed() const;
            virtual size_t FreeMemory() const;
        };
    }
}
