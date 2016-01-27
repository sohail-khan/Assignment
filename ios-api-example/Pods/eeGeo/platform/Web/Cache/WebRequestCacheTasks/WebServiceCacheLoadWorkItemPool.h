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
                class WebServiceCacheLoadWorkItemCallback
                {
                public:
                    typedef void (WebServiceCacheLoadWorkItemPool::*TCallback)(Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItem* cacheLoadWorkItem);
                    WebServiceCacheLoadWorkItemCallback(WebServiceCacheLoadWorkItemPool* context, TCallback callback);
                    virtual ~WebServiceCacheLoadWorkItemCallback() { };
                    virtual void operator()(Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItem* cacheLoadWorkItem);

                private:
                    TCallback m_callback;
                    WebServiceCacheLoadWorkItemPool* m_context;
                };

                class WebServiceCacheLoadWorkItemPool : private Eegeo::NonCopyable
                {
                public:
                    WebServiceCacheLoadWorkItemPool(const int poolSize);

                    ~WebServiceCacheLoadWorkItemPool();

                    bool HasFreeItems() const;
                    bool IsCacheOperationInProgress() const;
                    int GetFreeItemCount() const;
                    Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItem* TryGetFreeItem();

                private:
                    void AsyncCacheLoadWorkItemCompleted(
                            Eegeo::Web::Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItem* cacheLoadWorkItem);

                    std::vector<Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItem*> m_cacheLoadWorkItemPool;
                    std::deque<Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItem*> m_cacheLoadWorkItemFreeList;
                    Eegeo::Web::Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItemCallback m_asyncCacheLoadWorkItemCompleted;
                };
            }
        }
    }
}