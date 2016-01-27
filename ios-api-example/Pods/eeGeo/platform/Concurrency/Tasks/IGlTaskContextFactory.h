// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContext.h"

namespace Eegeo
{
    namespace Concurrency
    {
        namespace Tasks
        {
            class IGlTaskContextFactory
            {
            public:
                virtual ~IGlTaskContextFactory() { };
                virtual IGlTaskContext* Build() = 0;
            };
        }
    }
}


