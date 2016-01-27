// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GLHelpers.h"
#include "Types.h"
#include "Rendering.h"
#include "JpegImage.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace Jpeg
        {
            class IJpegLoader
            {
            public:
                virtual ~IJpegLoader() { };
                
                virtual void DecompressJpeg(Byte *jpeg, size_t len, JpegImage &image, bool invertVertically=false) = 0;
                
                virtual bool TryDecompressJpeg(Byte *jpeg, size_t len, JpegImage &image, bool invertVertically=false) = 0;
                
                virtual bool LoadJpgFromBuffer(
                                       Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo,
                                       const Byte* resourceBuffer,
                                       size_t resourceBufferSizeBytes,
                                       bool mipmap,
                                       bool invertVertically) = 0;
            };
        }
    }
}