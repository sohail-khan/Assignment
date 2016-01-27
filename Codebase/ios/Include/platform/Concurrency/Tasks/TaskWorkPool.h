// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Tasks.h"
#include "TaskWorker.h"
#include "ActiveObject.h"
#include "ITaskPoolMessage.h"
#include "ITaskPoolMessageDispatcher.h"
#include "WorkItem.h"
#include "TaskWorkPoolState.h"
#include "ITaskWorkerRunner.h"
#include "ThreadedTaskWorkerRunner.h"
#include "IWorkPool.h"
#include <vector>

namespace Eegeo
{
	namespace Concurrency
	{
		namespace Tasks
		{
			class TaskWorkPool : public Eegeo::Messaging::ActiveObject<Messages::ITaskPoolMessage*, Messages::ITaskPoolMessageDispatcher>, public IWorkPool
			{
			public:
                TaskWorkPool(Messaging::MessageQueue<Messages::ITaskPoolMessage*>& poolMessageQueue,
                             Messaging::MessageQueue<Messages::ITaskMessage*>& messageQueue,
                             std::vector<ITaskWorkerRunner*>& workers);

				~TaskWorkPool();

				void QueueWork(WorkItem* workItem);
                
                TaskWorkPoolState::Values GetState() const;

                void Start();
                void Stop();
                
                void OnMessageHandled(Messages::ITaskPoolMessage* message);
                
                bool HandleMessage(const Messages::WorkCompleteMessage& workCompleteMessage);
                bool HandleMessage(const Messages::WorkerStoppedMessage& workerStoppedMessage);
                

			private:
				std::vector<ITaskWorkerRunner*> m_workers;
                Messaging::MessageQueue<Messages::ITaskMessage*>& m_workerMessageQueue;
                TaskWorkPoolState::Values m_state;
                int m_stoppedWorkers;
			};
		}
	}
}

