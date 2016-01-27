// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "WorkItem.h"
#include "Helpers.h"
#include "Web.h"
#include "Cache.h"
#include "BidirectionalWebIOBus.h"

#include <string>

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			namespace WebRequestCacheTasks
			{
				class WebServiceCacheLoadWorkItem : public Eegeo::Concurrency::Tasks::WorkItem
				{
				public:
					WebServiceCacheLoadWorkItem(
						int id,
						Eegeo::Web::Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItemCallback& webRequestServiceCallback)
					: WorkItem(false)
                    , m_pWebMessageBus(NULL)
					, m_pFileIO(NULL)
					, m_webRequestServiceCallback(webRequestServiceCallback)
					, m_workItemId(id)
					, m_active(false)
					, m_cancelled(false)
					{

					}

					virtual ~WebServiceCacheLoadWorkItem() {}

					void Setup(
                            const std::string& url,
                            const TWebRequestId webRequestId,
                            Helpers::IFileIO* fileIO,
                            Web::TMessageBus* pWebMessageBus);

					void DoWorkCancelled ();
					void DoWork();
					void DoFinalizeOnMainThread();

                    bool IsActive() const { return m_active; }
                    int GetId() const { return m_workItemId; }
                private:
                    void ValidateFields() const;

                    std::string m_url;
                    TWebRequestId m_webRequestId;

                    Helpers::IFileIO* m_pFileIO;
                    Eegeo::Web::TMessageBus* m_pWebMessageBus;

                    WebServiceCacheLoadWorkItemCallback& m_webRequestServiceCallback;
                    int m_workItemId;
                    volatile bool m_active;
                    volatile bool m_cancelled;
				};
			}
		}
	}
}
