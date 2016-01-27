// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AsyncTexturing.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace AsyncTexturing
        {
            class IAsyncTextureRequestor
            {
            public:
                virtual IAsyncTexture& RequestTexture(const std::string& textureUrl, IAsyncTextureObserver* pObserver, bool tryToUpdateIfModified=false) = 0;
                virtual ~IAsyncTextureRequestor() {};
            };
        }
    }
}
