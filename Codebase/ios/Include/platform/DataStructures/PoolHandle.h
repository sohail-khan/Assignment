// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace DataStructures
    {  
        class PoolHandle
        {
            u32 m_handle;
            
        public:
            u32 GetCounter() { return (m_handle >> 16); }
            u32 GetIndex() { return (m_handle & 0x0000ffff); }
            
            PoolHandle(u32 counterValue, u32 indexValue)
            {
               m_handle = (counterValue << 16) | (indexValue & 0x0000ffff);
            }            

            PoolHandle()
            {
            	m_handle = 0;
            }
        };
    }
}