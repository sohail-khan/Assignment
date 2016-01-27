// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "FontCharacter.h"

namespace Eegeo
{
    namespace TextMeshes
    {
        namespace Internal
        {
            struct StringEntry;
            
            struct CharacterEntry
            {
                const Fonts::FontCharacter* fontCharacter;
                const StringEntry* stringEntry;
                float x;
                
                CharacterEntry(const Fonts::FontCharacter* fontCharacter, const StringEntry* stringEntry, float x)
                : fontCharacter(fontCharacter)
                , stringEntry(stringEntry)
                , x(x)
                {
                    
                }
                
                bool operator<(const CharacterEntry& other) const
                {
                    return fontCharacter->texturePage < other.fontCharacter->texturePage;
                }
            };
        }
    }
}
