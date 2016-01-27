// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BMFont.h"
#include "Fonts.h"
#include <string>

namespace Eegeo
{
    namespace Fonts
    {
        namespace BMFont
        {
            /*!
             *  Parses BMFont text format font descriptors.
             *  See http://www.angelcode.com/products/bmfont/doc/file_format.html
             */
            class BMFontTextReader : Eegeo::NonCopyable
            {
            public:
                //! Parses a BMFont font descriptor serialised in text format from an istream
                //! \param stream input stream providing BMFont descriptor
                //! \param fontReaderResult result output structure
                //! \result true if successful
                bool ParseFontFile(std::istream& stream, BMFontReaderResult& fontReaderResult);
            private:
                void InterpretInfo(const std::string &str, int start, BMFontInfo& out_fontInfo);
                void InterpretCommon(const std::string &str, int start, BMFontCommon& out_fontCommon);
                int InterpretCount(const std::string &str, int start);
                void InterpretPage(const std::string &str, int start, std::string& out_filename, int& out_pageId);
                void InterpretChar(const std::string &str, int start, u32& out_charUnicode, FontCharacter& out_fontCharacter);
                void InterpretKerning(const std::string &str, int start, BMFontKerning& kerningInfo);
                int SkipWhiteSpace(const std::string &str, u32 start);
                int FindEndOfToken(const std::string& str, u32 start);
            };
        }
    }
}
