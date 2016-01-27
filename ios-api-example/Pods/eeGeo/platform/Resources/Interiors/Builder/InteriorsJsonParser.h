// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Types.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                class InteriorsJsonParser : private Eegeo::NonCopyable
                {
                public:
                    bool TryParse(const std::string& interiorsJson, InteriorDto& out_interiorDto);
                };
            }
        }
    }
}

