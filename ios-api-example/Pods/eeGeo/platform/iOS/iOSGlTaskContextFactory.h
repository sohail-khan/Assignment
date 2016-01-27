// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContextFactory.h"
#include "IGlTaskContext.h"

namespace Eegeo
{
    namespace iOS
    {
        class iOSGlTaskContextFactory : public Concurrency::Tasks::IGlTaskContextFactory
        {
        public:
            Concurrency::Tasks::IGlTaskContext* Build();
        };
    }
}

