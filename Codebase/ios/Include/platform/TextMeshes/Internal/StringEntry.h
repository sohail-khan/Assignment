// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "VectorMath.h"

namespace Eegeo
{
    namespace TextMeshes
    {
        namespace Internal
        {
            struct StringEntry
            {
                m44 transform;
                float fontSize;
                float yOffset;
                float altitudeOffset;
                
                StringEntry(
                            const m44& transform,
                            float fontSize,
                            float yOffset,
                            float altitudeOffset)
                : transform(transform)
                , fontSize(fontSize)
                , yOffset(yOffset)
                , altitudeOffset(altitudeOffset)
                {
                }
                
            };
        }
    }
}

