// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ITaskMessage.h"
#include "Tasks.h"

namespace Eegeo
{
	namespace Concurrency
	{
		namespace Tasks
		{
			namespace Messages
			{
				class PerformWorkMessage : public ITaskMessage, protected Eegeo::NonCopyable
				{
				public:
					PerformWorkMessage(WorkItem* workItem);
					WorkItem& GetWorkItem() const;
					bool Handle(ITaskMessageDispatcher& dispatcher) const;

				private:
					WorkItem* m_pWorkItem;
				};
			}
		}
	}
}

