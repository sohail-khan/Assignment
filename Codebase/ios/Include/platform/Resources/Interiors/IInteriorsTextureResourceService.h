// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Rendering.h"
#include "Helpers.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorsTextureResourceService
            {
            public:
                virtual ~IInteriorsTextureResourceService() {;}
                
                virtual IInteriorsTextureResource* Create(const std::string& textureKey, const std::string& textureFileName) = 0;
                virtual IInteriorsTextureResource* CreateFromCubeMapFaces(const std::string& textureKey, const Eegeo::Helpers::CubeFaceFileNames& cubeFaceFileNames) = 0;
                virtual void Destroy(const std::string& textureKey) = 0;
                virtual bool Contains(const std::string& textureKey) const = 0;
                virtual IInteriorsTextureResource* Get(const std::string& textureKey) const = 0;
                
            };
        }
    }
}