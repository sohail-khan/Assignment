// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Tasks.h"

namespace Eegeo
{
	namespace Concurrency
	{
		namespace Tasks
		{
			class WorkItem : protected Eegeo::NonCopyable
			{
			public:
                WorkItem(bool deleteAfterFinalize=true);
				virtual ~WorkItem() {}
				void Work();
				void FinaliseOnMainThread();
                void WorkCancelled();
                
                bool IsComplete() const;
                bool IsFinalised() const;
                bool IsCancelled();
                bool ShouldDeleteAfterFinalize() const;
                void Cancel();
                
                const Priority::Values GetPriority() const { return m_priority; }
                
            protected:
                virtual void DoWork() = 0;
                virtual void DoFinalizeOnMainThread() = 0;
                virtual void DoWorkCancelled() { };
                virtual void SetPriority(Priority::Values priority) { m_priority = priority; }
                
			private:
				bool m_complete;
                bool m_finalized;
                bool m_deleteAfterFinalize;
                Priority::Values m_priority;
                volatile s32 m_cancelled;
			};
		}
	}
}


