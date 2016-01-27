// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <vector>

namespace Eegeo
{
    namespace Helpers
    {
        template<typename T, size_t N>
        T* end(T (&array)[N])
        {
            return array + N;
        }
        
        template< typename T, size_t N >
        std::vector<T> makeVector( const T (&array)[N] )
        {
            return std::vector<T>(array, array + N);
        }
    }
}
