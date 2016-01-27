// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Geometry
    {
        inline Eegeo::v2 PerpendicularRight(const Eegeo::v2& v)
        {
            return Eegeo::v2(v.y, -v.x);
        }

        float ClockwiseAngleInRadiansTo(Eegeo::v2 aNormalisedDir, Eegeo::v2 bNormalisedDir);
    }
}