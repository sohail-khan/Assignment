// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ActiveObject.h"
#include "ITaskMessage.h"
#include "ITaskPoolMessage.h"
#include "ITaskMessageDispatcher.h"
#include "Tasks.h"
#include "TaskWorkerState.h"

namespace Eegeo
{
	namespace Concurrency
	{
		namespace Tasks
		{
			class TaskWorker : public Eegeo::Messaging::ActiveObject<Messages::ITaskMessage*, Messages::ITaskMessageDispatcher>
			{
			public:
				TaskWorker(Messaging::MessageQueue<Messages::ITaskMessage*>& messageQueue,
                           Messaging::MessageQueue<Messages::ITaskPoolMessage*>& workPoolMessageQueue);
                virtual ~TaskWorker();
                virtual void Start();
                virtual void RequestStop() { };
                virtual void Stop();
                virtual void OnStop() { };
                
                void OnMessageHandled(Messages::ITaskMessage* message);
                
                bool IsRunning() const;
                TaskWorkerState::Values GetState() const;

                bool HandleMessage(const Tasks::Messages::StopWorkerMessage& stopWorkerMessage);
                bool HandleMessage(const Tasks::Messages::PerformWorkMessage& performWorkMessage);
                
            protected:
                virtual void PerformWork(WorkItem& workItem);
                
			private:
				Messaging::MessageQueue<Messages::ITaskPoolMessage*>& m_workPoolMessageQueue;
                TaskWorkerState::Values m_state;
			};
		}
	}
}

