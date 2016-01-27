// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContext.h"

namespace Eegeo
{
    namespace iOS
    {
        class iOSGlTaskContext : public Concurrency::Tasks::IGlTaskContext
        {
        public:
            iOSGlTaskContext();
            ~iOSGlTaskContext();
            void CreateContext();
            void SetContext();
            void FlushContext();
            void Unbind();
        private:
            void* m_pWorkerEAGLContext;
        };
    }
}
