// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Concurrency
    {
        namespace Tasks
        {
            class IGlTaskContext
            {
            public:
                virtual ~IGlTaskContext() { };
                virtual void CreateContext() = 0;
                virtual void SetContext() = 0;
                virtual void FlushContext() = 0;
                virtual void Unbind() = 0;
            };
        }
    }
}

