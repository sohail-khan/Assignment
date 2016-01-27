// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Tasks.h"

namespace Eegeo
{
	namespace Concurrency
	{
		namespace Tasks
		{
			namespace Messages
			{
				class ITaskPoolMessageDispatcher
				{
				public:
					virtual ~ITaskPoolMessageDispatcher() {};
                    virtual bool HandleMessage(const WorkCompleteMessage& stopWorkerMessage) = 0;
                    virtual bool HandleMessage(const WorkerStoppedMessage& stopWorkerMessage) = 0;
				};
			}
		}
	}
}


