// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IJpegLoader.h"
#include "Types.h"
#include "JpegImage.h"
#include "JpegType.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace Jpeg
        {
            class JpegLoader : protected Eegeo::NonCopyable, public IJpegLoader
            {
            public:
                void DecompressJpeg(Byte *jpeg, size_t len, JpegImage &image, bool invertVertically=false);
                
                bool TryDecompressJpeg(Byte *jpeg, size_t len, JpegImage &image, bool invertVertically=false);
                
                bool LoadJpgFromBuffer(
                                       Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo,
                                       const Byte* resourceBuffer,
                                       size_t resourceBufferSizeBytes,
                                       bool mipmap,
                                       bool invertVertically);
            };
        }
    }
}
