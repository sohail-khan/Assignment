// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "tr1.h"

namespace Eegeo
{
    namespace Fonts
    {

        class FontKerningTable : public Eegeo::NonCopyable
        {
        public:
            FontKerningTable(size_t reserveSize);
            
            void AddPair(u32 firstUnicode, u32 secondUnicode, s8 kerningValue);
            bool TryGet(u32 firstUnicode, u32 secondUnicode, s8& out_kerningValue) const;
        private:
            inline static u64 CharacterPairKey(u32 firstUnicode, u32 secondUnicode)
            {
                u64 pairKey = firstUnicode;
                pairKey <<= 32;
                pairKey |= secondUnicode;
                return pairKey;
            }
            
            typedef Eegeo::unordered_map<u64, s8>::type TPairKeyToKerningValues;
            TPairKeyToKerningValues m_pairKeyToKerningValues;
        };
    }
}
