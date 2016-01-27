// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Cache.h"

#include <vector>
#include <deque>

namespace Eegeo
{
    namespace Web
    {
        namespace Cache
        {
            namespace WebRequestCacheTasks
            {
                class WebServiceCacheStoreWorkItemCallback
                {
                public:
                    virtual ~WebServiceCacheStoreWorkItemCallback() { };
                    typedef void (WebServiceCacheStoreWorkItemPool::*TCallback)(Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItem* cacheStoreWorkItem) ;
                    WebServiceCacheStoreWorkItemCallback(WebServiceCacheStoreWorkItemPool* context, TCallback callback);
                    virtual void operator()(Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItem* cacheStoreWorkItem);
                private:
                    TCallback m_callback;
                    WebServiceCacheStoreWorkItemPool* m_context;
                };

                class WebServiceCacheStoreWorkItemPool : private Eegeo::NonCopyable
                {
                public:
                    WebServiceCacheStoreWorkItemPool(const int poolSize);

                    ~WebServiceCacheStoreWorkItemPool();

                    bool HasFreeItems() const;
                    bool IsCacheOperationInProgress() const;
                    int GetFreeItemCount() const;
                    Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItem* TryGetFreeItem();

                private:
                    void AsyncCacheStoreWorkItemCompleted(
                            Eegeo::Web::Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItem* cacheStoreWorkItem);

                    std::vector<Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItem*> m_cacheStoreWorkItemPool;
                    std::deque<Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItem*> m_cacheStoreWorkItemFreeList;
                    Eegeo::Web::Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItemCallback m_asyncCacheStoreWorkItemCompleted;
                };
            }
        }
    }
}