// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"


namespace Eegeo
{
    namespace ModelHelpers
    {
        m44 CreateFromTransformFromTranslationRotationScale(const v3 &translation, const Quaternion &rot, const v3 &scale);
    }
}
