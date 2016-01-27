// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>
#include <limits>

#include "PoolItemFactory.h"
#include "PoolHandle.h"
#include "PoolEntry.h"
#include "Types.h"

namespace Eegeo
{
    namespace DataStructures
    {        
        template <class T>
        class Pool : protected Eegeo::NonCopyable
        {
        private:
            std::vector<PoolEntry<T> > m_entries;
            PoolItemFactory<T> *m_pInstanceFactory;
            u32 m_nextFreeIndex;
            int m_count;
            
        public:
            int GetCount() const { return m_count; }
            int GetCapacity() const { return static_cast<int>(m_entries.size()); }
            bool GetIsAllocationAvailable() const { return !(m_nextFreeIndex == std::numeric_limits<unsigned int>::max()); }
            const std::vector<PoolEntry<T> >& GetEntries() { return m_entries; }
            
            Pool(int totalCapacity, PoolItemFactory<T> *pInstanceFactory);
            ~Pool();
            PoolHandle Allocate();
            void Release(PoolHandle handle);
            T Resolve(PoolHandle handle);
        };
    }
}

#include "PoolImpl.h"