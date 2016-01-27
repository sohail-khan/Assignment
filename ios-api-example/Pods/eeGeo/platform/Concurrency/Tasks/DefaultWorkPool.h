// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IWorkPool.h"
#include "Tasks.h"
#include "MessageQueue.h"
#include "TaskWorkPool.h"
#include "IGlTaskContextFactory.h"

namespace Eegeo
{
    namespace Concurrency
    {
        namespace Tasks
        {
            class DefaultWorkPool : protected Eegeo::NonCopyable, public IWorkPool
            {
            public:
                DefaultWorkPool(Eegeo::Concurrency::Tasks::IGlTaskContextFactory& taskContextFactory,
                				int numWorkers);
                ~DefaultWorkPool();
                
                void Start();
                void Stop();
                void QueueWork(WorkItem* workItem);
                void Update();
                TaskWorkPoolState::Values GetState() const;
            private:
                Messaging::MessageQueue<Messages::ITaskMessage*>* m_pWorkerMessageQueue;
                Messaging::MessageQueue<Messages::ITaskPoolMessage*>* m_pPoolMessageQueue;
                TaskWorkPool* m_pWorkPool;
                std::vector<TaskWorker*> m_workers;
                IGlTaskContextFactory& m_taskContextFactory;
            };
        }
    }
}
