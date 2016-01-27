// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "GLHelpers.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace AsyncTexturing
        {
            class IAsyncTexture
            {
            public:
            	virtual ~IAsyncTexture() {};
                virtual const std::string GetUrl() const = 0;
                virtual const Helpers::GLHelpers::TextureInfo& GetTextureInfo() const = 0;
                virtual void Release() = 0;
                virtual bool IsLoaded() const = 0;
                virtual bool IsComplete() const = 0;
            };
        }
    }
}
