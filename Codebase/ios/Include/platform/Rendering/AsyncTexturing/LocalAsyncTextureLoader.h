// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IAsyncTextureRequestor.h"
#include "Helpers.h"
#include "AsyncTexturing.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace AsyncTexturing
        {
            class LocalAsyncTextureLoader : protected Eegeo::NonCopyable, public IAsyncTextureRequestor
            {
            public:
                LocalAsyncTextureLoader(Eegeo::Helpers::ITextureFileLoader& textureFileLoader);
                ~LocalAsyncTextureLoader();

                IAsyncTexture& RequestTexture(const std::string& textureUrl, IAsyncTextureObserver* pObserver, bool tryToUpdateIfModified=false);
                
            private:
                Eegeo::Helpers::ITextureFileLoader& m_textureFileLoader;
            };
        }
    }
}