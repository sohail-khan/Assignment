// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Geometry
    {
        class ISpline
        {
        public:
            virtual ~ISpline() {}
            
            virtual void GetInterpolatedPositionInPlace(double t, dv3& out_position) const = 0;
            virtual bool IsValid() const = 0;
        };
        
    }
}