// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ITextureFileLoader.h"
#include "IJpegLoader.h"
#include "Types.h"
#include "MacTypes.h"
#include "GLHelpers.h"
#include <string>

namespace Eegeo
{
    namespace iOS
    {
        class iOSFileIO;
        
        using namespace Helpers;

        class iOSTextureFileLoader : public Eegeo::Helpers::ITextureFileLoader, protected Eegeo::NonCopyable
        {
            iOSFileIO* m_pFileIO;
            Eegeo::Helpers::Jpeg::IJpegLoader& m_jpegLoader;
            
            bool LoadPvrFromBuffer(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const Byte* resourceBuffer, size_t resourceBufferSizeBytes);
            bool LoadPngFromBuffer(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const Byte* resourceBuffer, size_t resourceBufferSizeBytes, bool mipmap, bool invertVertically);
            bool LoadJpgFromBuffer(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const Byte* resourceBuffer, size_t resourceBufferSizeBytes, bool mipmap, bool invertVertically);

        public:
            iOSTextureFileLoader(iOSFileIO *pFileIO, Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader);
            virtual ~iOSTextureFileLoader();
            
            bool LoadJPG(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& filename, bool mipmap, bool invertVertically);
            bool LoadPVR(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& filename);
            bool LoadPNG(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& filename, bool mipmap, bool invertVertically);

            virtual bool LoadFromBuffer(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& fileExtension, const Byte* resourceBuffer, size_t bufferSizeBytes, bool mipmap=false);
            virtual bool LoadTexture(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& fileName, bool mipmap = false);
            virtual bool LoadFromCubeFaces(Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo, const CubeFaceFileNames& cubeFaceFileNames);

        };
    }
}
