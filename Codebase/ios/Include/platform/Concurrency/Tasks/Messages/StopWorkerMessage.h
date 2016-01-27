// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ITaskMessage.h"

namespace Eegeo
{
	namespace Concurrency
	{
		namespace Tasks
		{
			namespace Messages
			{
				class StopWorkerMessage : public ITaskMessage, protected Eegeo::NonCopyable
				{
                public:
                    bool Handle(ITaskMessageDispatcher& dispatcher) const;
				};
			}
		}
	}
}


