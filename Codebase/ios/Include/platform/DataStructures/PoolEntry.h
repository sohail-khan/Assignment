// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace DataStructures
    {        
        template <class T>
        struct PoolEntry
        {
            bool allocated;
            u32 nextFreeIndex;
            u32 counter;
            T instance;
        };
    }
}