// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <string>

namespace Eegeo
{
    namespace Unicode
    {
        namespace Utf8
        {
            //! Counts the number of Unicode codepoints in a Utf-8 encoded string
            //! \param s a Utf-8 encoded byte sequence
            //! \param size in bytes of buffer s
            //! \return Return the number of Utf32 codepoints decoded from s up to but not including the first null character
            size_t Strnlen(const char *s, size_t size);
            
            //! \brief Decodes the next Unicode codepoint from a Utf-8 sequence iterator, and increments
            //! the iterator to one byte past the end of octet sequence for the decoded character.
            //!
            //! If an invalid octet sequence or codepoint is encountered on the input sequence, the replacement character U+FFFD
            //! is returned, and iter incremented by one element
            //! \param iter std::string const iterator pointing to the start of a Utf-8 string
            //! \param iterEnd std::string const iterator pointing to one element past the end of the string
            //! \return the Utf-32 codepoint decoded from iter
            u32 Next(std::string::const_iterator& iter, std::string::const_iterator iterEnd);
            
            //! \brief Decodes the next Unicode codepoint from a Utf-8 sequence iterator, and increments
            //! the iterator to one byte past the end of octet sequence for the decoded character.
            //!
            //! If an invalid octet sequence or codepoint is encountered on the input sequence, the replacement character U+FFFD
            //! is returned, and iter incremented by one element
            //! \param iter pointer to the start of a Utf-8 string
            //! \param iterEnd pointer to the element one past the end of the inputIter string
            //! \return the Utf-32 codepoint decoded from iter
            u32 Next(const char*& iter, const char* iterEnd);
            
            //! \brief Decodes the next Unicode codepoint from a Utf-8 sequence iterator.
            //!
            //! If an invalid octet sequence or codepoint is encountered on the input sequence, the replacement character U+FFFD
            //! is returned, and iter incremented by one element.
            //! \param iter std::string const iterator pointing to the start of a Utf-8 string
            //! \param iterEnd std::string const iterator pointing to one element past the end of the string
            //! \return the Utf-32 codepoint decoded from iter
            inline u32 PeekNext(std::string::const_iterator iter, std::string::const_iterator iterEnd)
            {
                return Next(iter, iterEnd);
            }
            
            //! \brief Decodes the next Unicode codepoint from a Utf-8 sequence iterator.
            //!
            //! If an invalid octet sequence or codepoint is encountered on the input sequence, the replacement character U+FFFD
            //! is returned, and iter incremented by one element
            //! \param iter pointer to the start of a Utf-8 string
            //! \param iterEnd pointer to the element one past the end of the inputIter string
            //! \return the Utf-32 codepoint decoded from iter
            inline u32 PeekNext(const char* iter, const char* iterEnd)
            {
                return Next(iter, iterEnd);
            }
            
            //! Counts the number of Unicode codepoints in a Utf-8 sequence range
            //! \param iter std::string const iterator pointing to the start of a Utf-8 sequence
            //! \param iterEnd std::string const iterator pointing to the element one past the end of the input sequence range
            //! \return Return the number of Utf-32 codepoints decoded from the input sequence
            size_t GetCodepointCount(std::string::const_iterator iter, std::string::const_iterator iterEnd);
            
            //! Counts the number of Unicode codepoints in a Utf-8 sequence range
            //! \param iter pointer to the start of a Utf-8 sequence
            //! \param iterEnd pointer to the element one past the end of the input sequence range
            //! \return Return the number of Utf-32 codepoints decoded from the input sequence
            size_t GetCodepointCount(const char* iter, const char* iterEnd);
            
            //! \brief Decodes Utf-8 sequence inputIter to a Utf-32 sequence, inserting results on outputIter.
            //!
            //! Example:
            //!
            //!     std::string utf8String;
            //!     std::vector<u32> utf32String;
            //!     Utf8::ToUtf32(utf8String.begin(), utf8String.end(), back_inserter(utf32String);
            //!
            //! If an invalid octet sequence or codepoint is encountered on the input sequence, the replacement character U+FFFD
            //! is inserted on output, and inputIter incremented by one element before continuing
            //!
            //! \param inputIter std::string const iterator pointing to the start of a Utf-8 string
            //! \param inputIterEnd std::string const iterator pointing to one element past the end of the inputIter string
            //! \param outputIter output std::iterator onto which the resulting Utf-32 characters are inserted
            //! \return the new value of outputIter
            template <typename TUtf32Iterator>
            inline TUtf32Iterator ToUtf32(std::string::const_iterator inputIter, std::string::const_iterator inputIterEnd, TUtf32Iterator outputIter)
            {
                while (inputIter < inputIterEnd)
                {
                    (*outputIter++) = Next(inputIter, inputIterEnd);
                }
                return outputIter;
            }
            
            //! \brief Decodes Utf-8 sequence inputIter to a Utf-32 sequence, inserting results on outputIter
            //!
            //! Example:
            //!
            //!     const char utf8String[] = "Example";
            //!     const char* end = utf8String + strlen(utf8String);
            //!     std::vector<u32> utf32String;
            //!     Utf8::ToUtf32(utf8String, end, back_inserter(utf32String);
            //!
            //! If an invalid octet sequence or codepoint is encountered on the input sequence, the replacement character U+FFFD
            //! is inserted on output, and inputIter incremented by one element before continuing
            //!
            //! \param inputIter pointer to the start of a Utf-8 string
            //! \param inputIterEnd pointer to the element one past the end of the inputIter string
            //! \param outputIter output std::iterator onto which the resulting Utf-32 characters are inserted
            //! \return the new value of outputIter
            template <typename TUtf32Iterator>
            inline TUtf32Iterator ToUtf32(const char* inputIter, const char* inputIterEnd, TUtf32Iterator outputIter)
            {
                while (inputIter < inputIterEnd)
                {
                    (*outputIter++) = Next(inputIter, inputIterEnd);
                }
                return outputIter;
            }
        };
    }
}
