// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Pool.h"

namespace Eegeo
{
    namespace DataStructures
    {
        template <typename T>
        Pool<T>::Pool(int totalCapacity, PoolItemFactory<T> *pInstanceFactory)
        :m_pInstanceFactory(pInstanceFactory),
        m_nextFreeIndex(0),
        m_count(0)
        {
            if(totalCapacity > 0)
            {
                PoolEntry<T>* pCurrent = NULL;
                
                m_entries.reserve(totalCapacity);
                for (int i = 0; i < totalCapacity; ++i)
                {
                    PoolEntry<T> entry;
                    m_entries.push_back(entry);
                    pCurrent = &(m_entries[i]);
                    
                    pCurrent->allocated = false;
                    pCurrent->nextFreeIndex = i + 1;
                    pCurrent->counter = 1;
                    pCurrent->instance = m_pInstanceFactory->CreateItem();
                    
                }
                pCurrent->nextFreeIndex = std::numeric_limits<unsigned int>::max();
            }
        }
        
        template <typename T>
        Pool<T>::~Pool()
        {
            for (size_t i = 0; i < m_entries.size(); ++i)
            {
            	PoolEntry<T>* pCurrent = &(m_entries[i]);
            	Eegeo_DELETE pCurrent->instance;
            }
            
            m_entries.clear();
        }
        
        
        template <typename T>
        PoolHandle Pool<T>::Allocate()
        {
            if (!GetIsAllocationAvailable())
            {
                //die
            }
            
            u32 index = m_nextFreeIndex;
            
            PoolEntry<T>* pCurrent = &(m_entries[index]);
            
            m_nextFreeIndex = pCurrent->nextFreeIndex;
            
            pCurrent->allocated = true;
            pCurrent->nextFreeIndex = std::numeric_limits<unsigned int>::max();
            pCurrent->counter = (pCurrent->counter + 1) & 0xffff;
            
            if (pCurrent->counter == 0)
            {
                pCurrent->counter = 1;
            }
            
            ++m_count;
            
            return PoolHandle(pCurrent->counter, index);
        }
    
        template <typename T>
        void Pool<T>::Release(PoolHandle handle)
        {
            u32 index = handle.GetIndex();
            
            PoolEntry<T>* pCurrent = &(m_entries[index]);
            pCurrent->allocated = false;
            pCurrent->nextFreeIndex = m_nextFreeIndex;
            pCurrent->counter = (pCurrent->counter + 1) & 0xffff;
            
            m_nextFreeIndex = index;
            
            --m_count;
        }
        
        template <typename T>
        T Pool<T>::Resolve(PoolHandle handle)
        {
            u32 index = handle.GetIndex();
            
            if (m_entries[index].counter != handle.GetCounter())
            {
                //die
            }
            
            T pInstance = m_entries[index].instance;
            return pInstance;
        }
    }
}
