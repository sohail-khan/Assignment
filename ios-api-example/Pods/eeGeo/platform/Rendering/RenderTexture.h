// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "GLHelpers.h"

namespace Eegeo
{
    namespace Rendering
    {
        class RenderTexture : public Eegeo::NonCopyable
        {
        public:
            RenderTexture(u32 width, u32 height, bool useDepth);
            virtual ~RenderTexture();
            
            void BeginRendering();
            void EndRendering();
            
            float Width() { return m_textureInfo.width; }
            float Height() { return m_textureInfo.height; }
            u32 TextureId() { return m_textureInfo.textureId; }
        private:
            u32 m_framebuffer;
            u32 m_depthBuffer;
            u32 m_stencilBuffer;
            u32 m_oldFrameBuffer;
            bool m_enabled;
            
            Helpers::GLHelpers::TextureInfo m_textureInfo;
        };
    }
}
