// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ITextureFileLoader.h"
#include "Types.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "IJpegLoader.h"
#include <string>

namespace Eegeo
{
    namespace Windows
    {
        using namespace Eegeo::Helpers;

        class WindowsTextureFileLoader : public Eegeo::Helpers::ITextureFileLoader, protected Eegeo::NonCopyable
        {
            Eegeo::Helpers::IFileIO* m_pFileIO;
            Eegeo::Helpers::Jpeg::IJpegLoader& m_jpegLoader;

            bool LoadPng(Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo, const std::string& filename, bool mipmap, bool invertVertically);
            
            bool LoadDDS(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& filename);
            bool LoadDDSFromStream(Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo, std::istream& stream);
            bool LoadDDSFromBuffer(Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo, const void* resourceBuffer, size_t resourceBufferSizeBytes);
            
            bool LoadPngFromStream(Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo, std::istream& stream, bool mipmap, bool invertVertically);
            bool LoadPngFromBuffer(Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo, const void* resourceBuffer, size_t resourceBufferSizeBytes, bool mipmap, bool invertVertically);
            static GLenum CalcPNGGLPixelFormat(int color_type);

            bool LoadJpg(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& filename, bool mipmap, bool invertVertically);
            Byte *CreateImageDataFromPngStream(std::istream& stream, u32& width, u32& height, int& colorType, bool invertVertically);
            
        public:
            WindowsTextureFileLoader(Eegeo::Helpers::IFileIO *pFileIO, Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader);
            virtual ~WindowsTextureFileLoader();
            
            virtual bool LoadTexture(Eegeo::Helpers::GLHelpers::TextureInfo& info, const std::string& fileName, bool mipmap = false);
            virtual bool LoadFromBuffer(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& fileExtension, const Byte* resourceBuffer, size_t bufferSizeBytes, bool mipmap=false);
            virtual bool LoadFromCubeFaces(Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo, const Helpers::CubeFaceFileNames& cubeFaceFileNames);
        };
    }
}
