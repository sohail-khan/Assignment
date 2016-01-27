// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IdTypes.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        class EnvironmentTexture
        {
        private:
            TTextureId m_texture;
            std::string m_url;
            int m_refCount;
            
        public:
            EnvironmentTexture(const std::string& url, TTextureId textureId)
            : m_refCount(0)
            , m_url(url)
            , m_texture(textureId)
            {
            }
            
            TTextureId GetTexture() const
            {
            	Eegeo_ASSERT(m_refCount >= 0, "invalid ref count -- mismatched Increment/Decrement");
                return m_texture;
            }
            
            void IncrementReferenceCount()
            {
                Eegeo_ASSERT(m_refCount >= 0, "invalid ref count -- mismatched Increment/Decrement");
                ++m_refCount;
            }
            
            void DecrementReferenceCount()
            {
                --m_refCount;
                Eegeo_ASSERT(m_refCount >= 0, "invalid ref count -- mismatched Increment/Decrement");
            }
            
            bool IsReferenced() const
            {
                Eegeo_ASSERT(m_refCount >= 0, "invalid ref count -- mismatched Increment/Decrement");
                return m_refCount > 0;
            }
        };
        
    }
}
