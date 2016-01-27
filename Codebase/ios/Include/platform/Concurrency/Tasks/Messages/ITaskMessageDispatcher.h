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
				class ITaskMessageDispatcher
				{
				public:
					virtual ~ITaskMessageDispatcher() {};
                    virtual bool HandleMessage(const StopWorkerMessage& stopWorkerMessage) = 0;
                    virtual bool HandleMessage(const PerformWorkMessage& stopWorkerMessage) = 0;
				};
			}
		}
	}
}


