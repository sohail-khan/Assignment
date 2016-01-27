// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Rendering
    {
        enum TextureMinifyType
        {
            TextureMinify_Nearest,
            TextureMinify_Linear,
            TextureMinify_NearestMipmap_Nearest,
            TextureMinify_LinearMipmap_Nearest,
            TextureMinify_NearestMipmap_Linear,
            TextureMinify_LinearMipmap_Linear
        };
    }
}
