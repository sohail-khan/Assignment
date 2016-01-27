// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "TaskWorker.h"
#include "IRunnable.h"
#include "ITaskWorkerRunner.h"
#include "Thread.h"

namespace Eegeo
{
    namespace Concurrency
    {
        namespace Tasks
        {
            class ThreadedTaskWorkerRunner : protected Eegeo::NonCopyable, public ITaskWorkerRunner
            {
            public:
                ThreadedTaskWorkerRunner(TaskWorker& taskWorker);
                ~ThreadedTaskWorkerRunner();
                void RequestStop();
                void Stop();
                void Start();
                bool IsRunning() const;
            private:
                TaskWorker& m_taskWorker;
                IRunnable* m_pRunnable;
                Thread* m_pThread;
            };
        }
    }
}
