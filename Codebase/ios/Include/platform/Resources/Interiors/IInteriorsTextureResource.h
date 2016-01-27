// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Types.h"
#include "Rendering.h"
#include "IdTypes.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorsTextureResource
            {
            public:
                virtual ~IInteriorsTextureResource() {;}
                
                virtual std::string GetName() const = 0;
                virtual Rendering::TTextureId GetTextureId() const = 0;
            };
        }
    }
}