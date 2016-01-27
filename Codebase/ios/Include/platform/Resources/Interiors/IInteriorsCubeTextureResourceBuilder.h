// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Helpers.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorsCubeTextureResourceBuilder
            {
            public:
                virtual ~IInteriorsCubeTextureResourceBuilder() {;}
                virtual IInteriorsTextureResource* Create(const std::string& textureResourceKey, const Helpers::CubeFaceFileNames& cubeFaceFilenames) = 0;
            };
        }
    }
}