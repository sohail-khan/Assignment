// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorsTextureResourceBuilder
            {
            public:
                virtual ~IInteriorsTextureResourceBuilder() {;}
                virtual IInteriorsTextureResource* Create(const std::string& textureResourceKey, const std::string& textureFilename) = 0;
            };
        }
    }
}