// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "GLHelpers.h"

#ifdef EEGEO_DROID

namespace Eegeo
{
    namespace Android
    {
    	bool LoadKtx (const void* data, size_t size, Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo);
    }
}

#endif
