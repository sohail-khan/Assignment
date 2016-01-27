// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#define         MASKBITS                0x3F
#define         MASKBYTE                0x80
#define         MASK2BYTES              0xC0
#define         MASK3BYTES              0xE0
#define         MASK4BYTES              0xF0
#define         MASK5BYTES              0xF8
#define         MASK6BYTES              0xFC


namespace Eegeo
{
	template <typename T>
	T AlignUp(const T in, u32 align)
	{
		T out = in;
        
		if(out % align)
		{
			out += align - (out % align);
		}
        
		return out;
	}
    
	template <typename T>
	T AlignDown(const T in, u32 align)
	{
		T out = in;
        
		if(out % align)
		{
			out -= (out % align);
		}
        
		return out;
	}
    
    inline void ConvertColourU32ToFloat(float* floatCol, const u32 colour)
	{
		floatCol[0] = ((float)((colour & 0xff000000) >> 24))/255.0f;
		floatCol[1] = ((float)((colour & 0x00ff0000) >> 16))/255.0f;
		floatCol[2] = ((float)((colour & 0x0000ff00) >>  8))/255.0f;
		floatCol[3] = ((float)((colour & 0x000000ff) >>  0))/255.0f;
	}
    
	inline u32 ConvertColourFloatToU32(const float* floatCol)
	{
		return (((u32)(floatCol[0] * 255.0f)) << 24) | (((u32)(floatCol[1] * 255.0f)) << 16) | (((u32)(floatCol[2] * 255.0f)) << 8) | (((u32)(floatCol[3] * 255.0f)));
	}
    
	inline u32 MakeRGBAu8(u8 r, u8 g, u8 b, u8 a)
	{
		return ((u32)(r) << 0) | ((u32)(g) << 8) | ((u32)(b) << 16) | ((u32)(a) << 24);
	}
    
	
	inline u32 UTF8ToU16(u16& dst, const char* utf8)
	{
		const u8* pBytes = (const u8*)utf8;
        
		
		if((pBytes[0] & MASK3BYTES) == MASK3BYTES)
		{
			dst = ((pBytes[0] & 0x0F) << 12) | ((pBytes[1] & MASKBITS) << 6) | (pBytes[2] & MASKBITS);
			return 3;
		}
		
		else if((pBytes[0] & MASK2BYTES) == MASK2BYTES)
		{
			dst = ((pBytes[0] & 0x1F) << 6) | (pBytes[1] & MASKBITS);
			return 2;
		}
		
		else
		{
			dst = pBytes[0];
			return 1;
		}
	}
	
	inline u32 U16ToUTF8(char* utf8, u16 src)
	{
		
		if(src < 0x80)
		{
			utf8[0] = ((char) src);
			return 1;
		}
		
		else if(src < 0x800)
		{
			utf8[0] = (char)(MASK2BYTES | (src >> 6));
			utf8[1] = (char)(MASKBYTE | (src & MASKBITS));
			return 2;
		}
		
		else
		{
			utf8[0] = (char)(MASK3BYTES | (src >> 12));
			utf8[1] = (char)(MASKBYTE | ((src >> 6) & MASKBITS));
			utf8[2] = (char)(MASKBYTE | (src & MASKBITS));
			return 3;
		}
	}
}
