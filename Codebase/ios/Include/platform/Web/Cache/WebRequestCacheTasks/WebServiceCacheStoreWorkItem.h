// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Cache.h"
#include "WorkItem.h"
#include "Helpers.h"
#include "Web.h"
#include <string>

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			namespace WebRequestCacheTasks
			{
				class WebServiceCacheStoreWorkItem : public Eegeo::Concurrency::Tasks::WorkItem
				{
				public:
					WebServiceCacheStoreWorkItem(WebServiceCacheStoreWorkItemCallback& webRequestServiceCallback)
					: WorkItem(false)
					, m_pHeaderData(NULL)
					, m_headerDataLength(0)
					, m_pBodyData(NULL)
					, m_bodyDataLength(0)
					, m_pFileIO(NULL)
					, m_pHttpCache(NULL)
					, m_webRequestServiceCallback(webRequestServiceCallback)
					, m_active(false)
					, m_success(false)
					{
					}

					virtual ~WebServiceCacheStoreWorkItem() {}

					//WebServiceCacheStoreWorkItem expects a resourceData it takes ownership of, and will delete[] when done
					void Setup(
						const std::string& url,
						Helpers::IFileIO* fileIO,
						Helpers::IHttpCache* httpCache,
						Byte* headerData,
						size_t headerDataLength,
						Byte* resourceData,
						size_t resourceDataLength);

					void DoWork();
					void DoFinalizeOnMainThread();

                    bool IsActive() const { return m_active; }

                private:
                    void AddToCache() const;

                    Byte *m_pHeaderData;
                    size_t m_headerDataLength;
                    Byte *m_pBodyData;
                    size_t m_bodyDataLength;
                    std::string m_url;
                    Helpers::IFileIO* m_pFileIO;
                    Helpers::IHttpCache* m_pHttpCache;
                    Eegeo::Web::Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItemCallback& m_webRequestServiceCallback;
                    bool m_active;
                    bool m_success;
                };
			}
		}
	}
}
