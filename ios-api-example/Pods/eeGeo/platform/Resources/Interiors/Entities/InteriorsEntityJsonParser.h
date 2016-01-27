// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "InteriorsEntityMetadata.h"
#include "document.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Entities
            {
                class InteriorsEntityJsonParser
                {
                public:
                    static void Parse(const rapidjson::Value& entitiesJson, TCategoryToEntitiesMetadata& out_categories);
                };
            }
        }
    }
}