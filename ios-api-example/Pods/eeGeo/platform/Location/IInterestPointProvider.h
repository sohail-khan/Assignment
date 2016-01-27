// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Location
    {
        class IInterestPointProvider
        {
        public:
            virtual ~IInterestPointProvider() { }
            virtual Eegeo::dv3 GetEcefInterestPoint() const = 0;
        };
    }
}

