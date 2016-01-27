// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "IGlTaskContextFactory.h"
#include "IGlTaskContext.h"

#import <OpenGL/OpenGL.h>
#import <Cocoa/Cocoa.h>

namespace Eegeo
{
    namespace OSX
    {
        class OSXGlTaskContextFactory : public Concurrency::Tasks::IGlTaskContextFactory
        {
        public:
            OSXGlTaskContextFactory(NSOpenGLPixelFormat* pParentGlPixelFormat)
            : m_pParentGlPixelFormat(pParentGlPixelFormat)
            {
            }
            
            Concurrency::Tasks::IGlTaskContext* Build();
            
        private:
            NSOpenGLPixelFormat* m_pParentGlPixelFormat;
        };
    }
}