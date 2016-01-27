// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        class FontInstance : Eegeo::NonCopyable
        {
        public:
            FontInstance(float outlineThickness,
                         float height,
                         float base,
                         float lineHeight,
                         float scaleW,
                         float scaleH,
                         const std::vector<u32>& textureList,
                         FontCharacterTable* characterTable,
                         FontKerningTable* kerningTable);

            ~FontInstance();
            
            float GetBase() const { return m_base; }
            float GetLineHeight() const { return m_lineHeight; }
            float GetHeight() const { return m_height; }
            int GetNumPages() const { return static_cast<int>(m_textureList.size()); }
            float GetOutlineThickness() const { return m_outlineThickness; }
            float GetScaleW() const { return m_scaleW; }
            float GetScaleH() const { return m_scaleH; }

            const std::vector<u32>& GetTextureList() const { return m_textureList; }

            const FontCharacter& GetCharacter(u32 charUnicode) const;
            const FontCharacter& GetCharacterOrDefault(u32 charUnicode) const;
            bool ContainsCharacter(u32 charUnicode) const;
            float GetKerning(u32 firstUnicode, u32 secondUnicode) const;

        private:
            float m_outlineThickness;
            float m_height;
            float m_base;
            float m_lineHeight;
            float m_scaleW;
            float m_scaleH;
            
            std::vector<u32> m_textureList;
            FontCharacterTable* m_characterTable;
            FontKerningTable* m_kerningTable;
        };
    }
}
