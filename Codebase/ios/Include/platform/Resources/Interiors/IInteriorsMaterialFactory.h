// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Rendering.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorsMaterialFactory
            {
            public:
                virtual ~IInteriorsMaterialFactory() {;}
                virtual Eegeo::Rendering::Materials::IMaterial* TryCreate(const InteriorMaterialData& interiorMaterialData) = 0;
            };
        }
    }
}