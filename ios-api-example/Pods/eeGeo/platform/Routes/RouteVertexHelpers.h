// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Routes
    {
        class RouteVertexHelpers
        {
        public:
            static v3 EcefToLocalPoint(const dv3& ecefPoint, const dv3& ecefOrigin);
        };
    }
}
