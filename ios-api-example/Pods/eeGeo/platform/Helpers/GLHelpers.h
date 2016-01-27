// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Graphics.h"
#include "TextureMinifyType.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace GLHelpers
        {
            struct TextureInfo
            {
                TextureInfo()
                : textureId(0)
                , width(0)
                , height(0)
                {}
                
                u32 textureId;
                int width;
                int height;
            };

            GLint GetMinifyParam(Rendering::TextureMinifyType minifyType);
            
            void SetUniformTextureSampler(Rendering::GLState& glState, int uniformSampler, int samplerIndex);
            
            void BindTexture2D(Rendering::GLState& glState, int samplerIndex, u32 textureId, Rendering::TextureMinifyType minifyType, bool repeat);

            //! compensate for ANGLE's lacking implementation of concurrent access to multiple contexts by allowing us to lock around usages of GL on Windows only
            #if defined(EEGEO_WIN)
            void EnterGLContextGuard();
            void ExitGLContextGuard();
            #else
            inline void EnterGLContextGuard() {}
            inline void ExitGLContextGuard() {}
            #endif

            //provides RAII locking for the GL context specifically
            struct LockGL
            {
                LockGL()
                {
                    EnterGLContextGuard();
                }

                ~LockGL()
                {
                    ExitGLContextGuard();
                }
            };
            
            //! clears GL bitplanes. Depth and stencil buffers are cleared to default values.
            //! Color buffer is cleared to color previously set with glClearColor (or GLState::ClearColor)
            inline void ClearBuffers()
            {
                Eegeo_GL(glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE));
                Eegeo_GL(glDepthMask(GL_TRUE))
                Eegeo_GL(glStencilMask(0xffffffff))
                Eegeo_GL(glDisable(GL_SCISSOR_TEST));
    #ifdef EEGEO_OSX
                Eegeo_GL(glClearDepth(1));
    #else
                Eegeo_GL(glClearDepthf(1));
    #endif
                Eegeo_GL(glClearStencil(0));
                
                
                Eegeo_GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
            }
            
            int GetTextureLoaderSamplerIndex();
         }
    }
}
