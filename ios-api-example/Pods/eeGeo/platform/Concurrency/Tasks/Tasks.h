// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
	namespace Concurrency
	{
		namespace Tasks
		{
            namespace Priority
            {
                enum Values
                {
                    Immediate, // or as close to as possible
                    Standard,
                    Max
                };
            }
            
			namespace Messages
			{
				class ITaskMessage;
				class ITaskMessageDispatcher;
                class PerformWorkMessage;
                class StopWorkerMessage;
                class WorkerStoppedMessage;
                class WorkCompleteMessage;
			}
            
            class TaskWorker;
            class TaskWorkPool;
            class WorkItem;
            class IWorkPool;
            class DefaultWorkPool;
            class IGlTaskContextFactory;
            class IGlTaskContext;
		}
	}
}

