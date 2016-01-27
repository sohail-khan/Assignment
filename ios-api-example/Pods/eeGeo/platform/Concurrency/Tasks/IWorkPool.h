// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "WorkItem.h"
#include "TaskWorkPoolState.h"

namespace Eegeo
{
    namespace Concurrency
    {
        namespace Tasks
        {
            class IWorkPool
            {
            public:
                virtual ~IWorkPool() { };
                virtual void Start() = 0;
                virtual void Stop() = 0;
                virtual void QueueWork(WorkItem* workItem) = 0;
                virtual TaskWorkPoolState::Values GetState() const = 0;
            };
        }
    }
}

