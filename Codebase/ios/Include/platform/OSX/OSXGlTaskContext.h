// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContext.h"

#import <OpenGL/OpenGL.h>
#import <Cocoa/Cocoa.h>

namespace Eegeo
{
    namespace OSX
    {
        class OSXGlTaskContext : public Concurrency::Tasks::IGlTaskContext
        {
        public:
            OSXGlTaskContext(NSOpenGLPixelFormat* pPixelFormat);
            ~OSXGlTaskContext();
            void CreateContext();
            void SetContext();
            void FlushContext();
            void Unbind();
        private:
            NSOpenGLContext* m_pWorkerContext;
            NSOpenGLPixelFormat* m_pParentGlPixelFormat;
        };
    }
}