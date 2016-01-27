// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IAsyncTexture.h"
#include "GLHelpers.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace AsyncTexturing
        {
            class Texture : protected Eegeo::NonCopyable, public IAsyncTexture
            {
            public:
                static Texture* Create(const std::string& textureUrl, const Helpers::GLHelpers::TextureInfo& textureInfo);
                static Texture* CreateNull();
                
                Texture(const std::string& textureUrl, const Helpers::GLHelpers::TextureInfo& textureInfo);
                ~Texture();
                const std::string GetUrl() const;
                const Helpers::GLHelpers::TextureInfo& GetTextureInfo() const;
                void Release();
                bool IsLoaded() const;
                bool IsComplete() const;
                
            private:
                void DeleteGLTexture();
                
                std::string m_textureUrl;
                Helpers::GLHelpers::TextureInfo m_textureInfo;
                bool m_isLoaded;
            };
        }
    }
}
