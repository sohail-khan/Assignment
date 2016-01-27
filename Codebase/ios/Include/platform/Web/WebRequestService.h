// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Web.h"
#include "BidirectionalWebIOBus.h"
#include "ICallback.h"
#include "IWebLoadRequest.h"
#include "CacheStoreOperation.h"
#include "WebServiceCacheTasks.h"
#include "Tasks.h"
#include "Helpers.h"
#include "WebServiceCacheLoadWorkItemPool.h"
#include "WebServiceCacheStoreWorkItemPool.h"

#include <set>
#include <string>

namespace Eegeo
{
	namespace Web
	{
        class WebRequestService : public Eegeo::NonCopyable
		{
		public:
			WebRequestService(
                    const Eegeo::Web::WebIOConfig& config,
                    Eegeo::Web::TMessageBus& webMessageBus,
                    Helpers::IFileIO& fileIO,
                    Helpers::IHttpCache& httpCache,
                    const Eegeo::Web::WebProxySettings& webProxySettings);

			~WebRequestService();

			void EnqueueLoad(IWebLoadRequest* pWebRequest);
			void EnqueueCancel(IWebLoadRequest* pWebRequest);

			void Update();

            // caching stuff, TODO: refactor out into own types
            void SetWorkPool(Eegeo::Concurrency::Tasks::IWorkPool* pWorkPool);
        private:
            void EnqueueCacheLoad(IWebLoadRequest* pWebRequest);
            void DeleteCancelledRequests();
            void OnWebResponseFromWireMessageHandler(const WebResponseFromWireMessage& message);
            void OnWebResponseFromCacheMessageHandler(const WebResponseFromCacheMessage& message);
            void OnWebResponseFallBackToCacheMessageHandler(const WebResponseFallBackToCacheMessage& message);
            void ExecuteCallbackAndCleanup(IWebLoadRequest* pWebRequest, IWebResponse* pWebResponse);

            Eegeo::Web::TMessageBus& m_webMessageBus;
            
            Helpers::TCallback1<WebRequestService, const WebResponseFromWireMessage&> m_webResponseFromWireMessageHandler;
            Helpers::TCallback1<WebRequestService, const WebResponseFromCacheMessage&> m_webResponseFromCacheMessageHandler;
            Helpers::TCallback1<WebRequestService, const WebResponseFallBackToCacheMessage&> m_webResponseFallBackToCacheMessageHandler;

            std::set<IWebLoadRequest*> m_webRequestsAwaitingResponse;
            std::vector<IWebLoadRequest*> m_cancelledRequests;

            // caching stuff, TODO: refactor out into own types
            void DispatchCacheLoadRequestToWorkPool(IWebLoadRequest* pWebRequest);
            void IssueCacheLoadRequests();
            void IssueCacheStoreRequests();

            bool PendingCacheStoreOperationExists(const std::string& url) const;
            void DestroyPendingCacheStoreOperations();

            std::list<IWebLoadRequest*> m_cacheRequestsNotYetSent;
            std::set<IWebLoadRequest*> m_cacheRequestsAwaitingResponse;

            Eegeo::Helpers::IFileIO& m_fileIO;
            Eegeo::Helpers::IHttpCache& m_httpCache;
            const Eegeo::Web::WebProxySettings& m_webProxySettings;

            Eegeo::Concurrency::Tasks::IWorkPool* m_pWorkPool;

            typedef std::deque<Cache::WebRequestCacheTasks::CacheStoreOperation> TCacheStoreOperations;
            TCacheStoreOperations m_pendingCacheStoreOperations;
            Eegeo::Web::Cache::WebRequestCacheTasks::WebServiceCacheLoadWorkItemPool m_cacheLoadWorkItemPool;
            Eegeo::Web::Cache::WebRequestCacheTasks::WebServiceCacheStoreWorkItemPool m_cacheStoreWorkItemPool;
            bool m_cacheLoadPoolExhaustedLastFrame;
            bool m_cacheStorePoolExhaustedLastFrame;
        };
	}
}
