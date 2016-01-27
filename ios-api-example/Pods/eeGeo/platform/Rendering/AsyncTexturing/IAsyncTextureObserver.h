// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AsyncTexturing.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace AsyncTexturing
        {
            class IAsyncTextureObserver
            {
            public:
            	virtual ~IAsyncTextureObserver() {};
                virtual void OnTextureLoadSuccess(const IAsyncTexture& loadedTexture) = 0;
                virtual void OnTextureLoadFail(const IAsyncTexture& loadedTexture) = 0;
            };
        }
    }
}
