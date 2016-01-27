// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Unicode
    {
        /*!
         *  Helper methods for decoding Utf8 byte streams to Utf32 codepoints
         */
        class UnicodeConverter
        {
        public:
            //! \deprecated For legacy app support. New apps should use Eegeo::Utf8::Next / Eegeo::Utf8::PeekNext
            static u32 DecodeUtf8Character(const char *text, size_t bufferSize, int pos, int *nextPos);
            
            //! Converts a Utf-8 input string to Utf-32.
            //! Invalid octet sequences or invalid characters are replaced with U+FFFD
            //! \param textUtf8 input Utf-8 character sequence
            //! \param out_textUtf32 output vector populated with resulting Utf-32 sequence
            static void Utf8ToUtf32(const std::string& textUtf8, std::vector<u32>& out_textUtf32);
            
            //! Converts a Utf-8 input string to Utf-32.
            //! Invalid octet sequences or invalid characters are replaced with U+FFFD
            //! \param textStr input Utf-8 character sequence buffer
            //! \param textLength size in bytes of textUtf8 buffer
            //! \param out_textUtf32 output vector populated with resulting Utf-32 sequence
            static void Utf8ToUtf32(const char* textStr, int textLength, std::vector<u32>& out_textUtf32);
        };
    }
}
