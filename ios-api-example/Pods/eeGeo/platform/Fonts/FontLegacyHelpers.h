// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fonts.h"
#include "Types.h"

namespace Eegeo
{
    namespace Fonts
    {
        /*!
         *  \deprecated Helper methods to provide support for legacy apps that relied on functionality previously on Eegeo::Fonts::FontInstance. Not for use by new applications 
         */
        namespace FontLegacyHelpers
        {
            size_t LimitTextWidth(const FontInstance& font, const char* textUtf8, float width);
            
            u32 TruncateString(const FontInstance& font, const char* text, float limit);
            
            u32 FormatString (const FontInstance& font, const char* text, float lineLength, char* formattedText, u32 maxLength);
            
            int SplitString (const char* text, u32* pOffsets, u32 maxLines);
            
            float GetStringWidth (const FontInstance& font, const char* text);
            
            float GetStringWidth (const FontInstance& font, const char* text, u32 count);
            
            float GetStringWidthMultiLine (const FontInstance& font, const char* text);
        }
    }
}
