// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SceneModelResourceBase.h"
#include "Types.h"
#include "IAsyncTexture.h"
#include "IdTypes.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelTextureResource : public SceneModelResourceBase, private Eegeo::NonCopyable
            {
            public:
                
                SceneModelTextureResource(const std::string& name, AsyncTexturing::IAsyncTexture* pAsyncTexture)
                : SceneModelResourceBase(name)
                , m_pAsyncTexture(pAsyncTexture)
                {
                    Eegeo_ASSERT(pAsyncTexture != NULL);
                }
                
                ~SceneModelTextureResource()
                {
                    m_pAsyncTexture->Release();
                }
                
                TTextureId GetTexture() const { return m_pAsyncTexture->GetTextureInfo().textureId; }
                
            private:
                
                AsyncTexturing::IAsyncTexture* m_pAsyncTexture;
                
            };
        }
    }
}