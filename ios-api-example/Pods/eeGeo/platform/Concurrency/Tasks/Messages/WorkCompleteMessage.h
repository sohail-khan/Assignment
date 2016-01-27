// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ITaskPoolMessage.h"
#include "Tasks.h"

namespace Eegeo
{
	namespace Concurrency
	{
		namespace Tasks
		{
			namespace Messages
			{
				class WorkCompleteMessage : public ITaskPoolMessage, protected Eegeo::NonCopyable
				{
				public:
					WorkCompleteMessage(WorkItem* workItem);
					WorkItem& GetWorkItem() const;
					bool Handle(ITaskPoolMessageDispatcher& dispatcher) const;
                    
				private:
					WorkItem* m_pWorkItem;
				};
			}
		}
	}
}
