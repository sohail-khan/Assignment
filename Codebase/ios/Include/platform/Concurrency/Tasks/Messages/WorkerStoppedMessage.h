// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ITaskPoolMessage.h"
#include "Tasks.h"

namespace Eegeo
{
    namespace Concurrency
    {
        namespace Tasks
        {
            namespace Messages
            {
                class WorkerStoppedMessage : public ITaskPoolMessage
                {
                public:
                    bool Handle(ITaskPoolMessageDispatcher& dispatcher) const;
                };
            }
        }
    }
}
