//
//  Utf8Decoder.h
//  apps-on-maps
//
//  Copyright (c) 2013 eeGeo. All rights reserved.
//

#ifndef apps_on_maps_Utf8Decoder_h
#define apps_on_maps_Utf8Decoder_h

#include "Types.h"
#include <iterator>

namespace EegeoUtf8Internal
{
    template <typename TOctetIterator>
    class Decoder
    {
    public:
        inline u32 Next(TOctetIterator& iter, TOctetIterator iterEnd);

        inline size_t GetCodepointCount(TOctetIterator iter, TOctetIterator iterEnd);

        template <typename TUtf32Iterator>
        inline TUtf32Iterator Utf8ToUtf32(TOctetIterator inputIter, TOctetIterator inputIterEnd, TUtf32Iterator outputIter)
        {
            while (inputIter < inputIterEnd)
            {
                (*outputIter++) = Next(inputIter, inputIterEnd);
            }
            return outputIter;
        }
    private:
        inline bool TryDecode(TOctetIterator& iter, TOctetIterator iterEnd, u32& codepoint);

        inline size_t GetOctetSequenceCount(u8 leadOctet);
        
        inline bool IsCodepointValidForSequenceCount(u32 codepoint, size_t sequenceCount);

        inline u8 GetOctet(TOctetIterator it)
        {
            u8 octet = static_cast<u8>((*it) & 0xff);
            return octet;
        }
        
        inline bool IsValidOctet(u8 octet)
        {
            // false if a red character in http://en.wikipedia.org/wiki/UTF-8#Codepage_layout
            return octet < 0xC0 || (octet > 0xC1 && octet < 0xF5);
        }
        
        inline bool IsContinuationOctet(u8 octet)
        {
            // top 2 bits == 10......
            return ((octet & 0xC0) == 0x80);
        }
        
        inline bool IsValidLeadOctet(u8 octet)
        {
            return IsValidOctet(octet) && !IsContinuationOctet(octet);
        }
        
        inline bool IsValidContinuationOctet(u8 octet)
        {
            return IsValidOctet(octet) && IsContinuationOctet(octet);
        }
    };
    
    template <typename TOctetIterator>
    inline u32 Decoder<TOctetIterator>::Next(TOctetIterator& iter, TOctetIterator iterEnd)
    {
        TOctetIterator restoreIter = iter;
        u32 codepoint = 0;
        
        if (!TryDecode(iter, iterEnd, codepoint))
        {
            const u32 replacementCodepoint = 0xFFFD;
            codepoint = replacementCodepoint;
            iter = restoreIter;
        }
        
        ++iter;
        
        return codepoint;
    }
    
    template <typename TOctetIterator>
    inline size_t Decoder<TOctetIterator>::GetCodepointCount(TOctetIterator iter, TOctetIterator iterEnd)
    {
        int count = 0;
        while (iter < iterEnd)
        {
            // continuation octet has high bits 10..
            if (((*iter) & 0xc0) != 0x80)
            {
                count++;
            }
            ++iter;
        }
        return count;
    }
    
    template <typename TOctetIterator>
    inline bool Decoder<TOctetIterator>::TryDecode(TOctetIterator& iter, TOctetIterator iterEnd, u32& codepoint)
    {
        //  http://en.wikipedia.org/wiki/UTF-8
        //
        //  Octet  Codepoint range         Byte 1       Byte 2      Byte 3      Byte 4
        //  1      U+0000  to U+007F       0xxxxxxx
        //  2      U+0080  to U+07FF       110xxxxx     10xxxxxx
        //  3      U+0800  to U+FFFF       1110xxxx     10xxxxxx	10xxxxxx
        //  4      U+10000 to U+10FFFF     11110xxx     10xxxxxx	10xxxxxx	10xxxxxx

        const u8 leadOctet = GetOctet(iter);
        if (!IsValidLeadOctet(leadOctet))
        {
            return false;
        }
        
        size_t octetSequenceCount = GetOctetSequenceCount(leadOctet);
        
        if (iter + octetSequenceCount > iterEnd)
        {
            return false;
        }
        
        u8 octet = 0;
        
        switch (octetSequenceCount)
        {
            case 1:
                codepoint = leadOctet & 0x7F;
                break;
            case 2:
                codepoint = (leadOctet & 0x1F) << 6;
                
                octet = GetOctet(++iter);
                if (!IsValidContinuationOctet(octet))
                    return false;
                codepoint |= (octet & 0x3F);
                break;
            case 3:
                codepoint = (leadOctet & 0x0F) << 12;
                
                octet = GetOctet(++iter);
                if (!IsValidContinuationOctet(octet))
                    return false;
                codepoint |= (octet & 0x3F) << 6;
                
                octet = GetOctet(++iter);
                if (!IsValidContinuationOctet(octet))
                    return false;
                codepoint |= (octet & 0x3F);
                break;
            case 4:
                codepoint = (leadOctet & 0x07) << 18;
                
                octet = GetOctet(++iter);
                if (!IsValidContinuationOctet(octet))
                    return false;
                codepoint |= (octet & 0x3F) << 12;
                
                octet = GetOctet(++iter);
                if (!IsValidContinuationOctet(octet))
                    return false;
                codepoint |= (octet & 0x3F) << 6;
                
                octet = GetOctet(++iter);
                if (!IsValidContinuationOctet(octet))
                    return false;
                codepoint |= (octet & 0x3F);
                break;
            default:
                return false;
        }
        
        return IsCodepointValidForSequenceCount(codepoint, octetSequenceCount);
    }
    
    template <typename TOctetIterator>
    inline size_t Decoder<TOctetIterator>::GetOctetSequenceCount(u8 leadOctet)
    {
        if (leadOctet <= 0x7F)
        {
            // high bit == 0
            return 1;
        }
        else if ((leadOctet & 0xE0) == 0xC0)
        {
            // 3 high bits == 110
            return 2;
        }
        else if ((leadOctet & 0xF0) == 0xE0)
        {
            // 4 high bits == 1110
            return 3;
        }
        else if ((leadOctet & 0xF8) == 0xF0)
        {
            // 5 high bits == 11110
            return 4;
        }
        else
        {
            return 0;
        }
    }
    
    template <typename TOctetIterator>
    inline bool Decoder<TOctetIterator>::IsCodepointValidForSequenceCount(u32 codepoint, size_t sequenceCount)
    {
        if (codepoint > 0x10FFFF)
        {
            return false;
        }
        
        if (codepoint >= 0xD800 && codepoint <= 0xDFFF)
        {
            // treat surrogates as invalid codepoints
            return false;
        }
        
        if (codepoint <= 0x7F)
        {
            return sequenceCount == 1;
        }
        else if (codepoint <= 0x7FF)
        {
            return sequenceCount == 2;
        }
        else if (codepoint <= 0xFFFF)
        {
            return sequenceCount == 3;
        }
        
        return sequenceCount == 4;
    }

}

#endif
