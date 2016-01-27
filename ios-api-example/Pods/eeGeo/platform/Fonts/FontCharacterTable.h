// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "FontCharacter.h"
#include "tr1.h"
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        class FontCharacterTable : public Eegeo::NonCopyable
        {
        public:
            FontCharacterTable(size_t reserveSize);
            
            void AddCharacter(u32 charUnicode, const FontCharacter& fontCharacter);
            
            const FontCharacter& GetCharacter(u32 charUnicode) const;
            const FontCharacter& GetCharacterOrDefault(u32 charUnicode) const;
            bool ContainsCharacter(u32 charUnicode) const;
            void SetDefaultCharacter(const FontCharacter& defaultCharacter);
        private:
            std::vector<FontCharacter> m_characters;
            
            typedef Eegeo::unordered_map<u32, int>::type TUnicodeToIndex;
            TUnicodeToIndex m_unicodeToIndex;
            
            FontCharacter m_defaultCharacter;
        };
    }
}
