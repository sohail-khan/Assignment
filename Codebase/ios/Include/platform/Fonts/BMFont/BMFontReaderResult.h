// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BMFontInfo.h"
#include "BMFontCommon.h"
#include "Fonts.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Fonts
    {
        namespace BMFont
        {
            struct BMFontReaderResult
            {
                BMFontInfo fontInfo;
                BMFontCommon fontCommon;
                std::vector<std::string> texturePageFilenames;
                FontKerningTable* kerningTable;
                FontCharacterTable* characterTable;
                
                BMFontReaderResult()
                : kerningTable(NULL)
                , characterTable(NULL)
                {
                    
                }
            };
        }
    }
}
