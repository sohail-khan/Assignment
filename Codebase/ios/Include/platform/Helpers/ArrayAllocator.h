// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <memory>

namespace Eegeo
{
    namespace Helpers
    {
        template<typename T, size_t maxElements>
        class ArrayAllocator : public std::allocator<T>
        {
        public:
            typedef typename std::allocator<T>::pointer pointer;
            typedef typename std::allocator<T>::size_type size_type;

			ArrayAllocator()
			{ }
			
			template <typename U>
			ArrayAllocator(ArrayAllocator<U, maxElements> const &) {}
            
            pointer allocate(size_type allocElements, void* hint = 0)
            {
                if (allocElements > maxElements)
                {
                    Eegeo_ASSERT(false);
                    return NULL;
                }
                return reinterpret_cast<T*>(m_buffer);
            }
            
            void deallocate(pointer p, size_type n) {}
            
            template<typename TOther>
            struct rebind { typedef ArrayAllocator<TOther, maxElements> other; };
        private:
            char m_buffer[sizeof( T[maxElements]) ];
        };
    }
}