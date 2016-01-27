// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Fonts
    {
        struct FontCharacter
        {
            float x;
            float y;
            float width;
            float height;
            float offsetX;
            float offsetY;
            float advanceX;
            int texturePage;

            FontCharacter();
        };
    }
}
