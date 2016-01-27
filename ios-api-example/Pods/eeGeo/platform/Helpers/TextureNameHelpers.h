// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace Helpers
    {
        namespace TextureNameHelpers
        {
            const std::string GetPlatformTextureExtension(bool isAlpha);
            bool TextureIsAlpha(const std::string &textureName);
            const std::string GetTextureExtension(const std::string &textureName);
            std::string StripLastExtension(const std::string& textureName);
            
            std::string GetImageNameForDevice(const std::string& name,
                                              const std::string& ext);
        }
    }
}