// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <iostream>
#include "TaskWorker.h"
#include "IGlTaskContext.h"

namespace Eegeo
{
    namespace Concurrency
    {
        namespace Tasks
        {
            class GlTaskWorker : public TaskWorker
            {
            public:
                GlTaskWorker(IGlTaskContext* glTaskContext,
                             Messaging::MessageQueue<Messages::ITaskMessage*>& messageQueue,
                             Messaging::MessageQueue<Messages::ITaskPoolMessage*>& workPoolMessageQueue);
                ~GlTaskWorker();
                
            protected:
                void PerformWork(WorkItem& workItem);
                
                void OnStop();

            private:
                IGlTaskContext* m_pContext;
            };
        }
    }
}
