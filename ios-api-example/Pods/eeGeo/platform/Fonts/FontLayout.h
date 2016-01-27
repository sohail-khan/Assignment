// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        class FontLayout : Eegeo::NonCopyable
        {
        public:
            FontLayout(const FontInstance& fontInstance);
            
            float GetTextWidth(const char* textUtf8, size_t bufferLen) const;
            
            float GetTextWidthUtf32(std::vector<u32>::const_iterator textUtf32Start, std::vector<u32>::const_iterator textUtf32End) const;

        private:
            const FontInstance& m_fontInstance;
        };
    }
}
