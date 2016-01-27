// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "Helpers.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        class FontLoader : protected Eegeo::NonCopyable
        {
            Eegeo::Helpers::IFileIO& fileIO;
            Eegeo::Helpers::ITextureFileLoader& textureFileLoader;
            
        public:
            FontLoader(Eegeo::Helpers::IFileIO& fileIO,
                       Eegeo::Helpers::ITextureFileLoader& textureFileLoader);
            
            //! Loads a text-format BMFont desciptor, generating a FontInstance object from it, and loads referenced textures for the font
            FontInstance* Load(const std::string& fontFilename, bool generateMipMaps);
            
        private:
            void LoadFontPageTextures(const std::vector<std::string>& texturePageFilenames, bool mipMap, int expectedWidth, int expectedHeight, std::vector<u32>& out_textureIds);
            
            bool SetupReplacementCharacter(FontCharacterTable& characterTable);
        };
    }
}