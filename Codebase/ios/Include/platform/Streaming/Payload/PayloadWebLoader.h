// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Web.h"
#include "Helpers.h"
#include "Streaming.h"
#include "WebLoadRequestCompletionCallback.h"
#include <vector>
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Helpers
    {
        class IHttpCache;
    }
    
    namespace Streaming
    {
        class PayloadWebLoader : public Eegeo::NonCopyable
        {   
        public:
            PayloadWebLoader(Web::IWebLoadRequestFactory& webLoadRequestFactory,
                             Helpers::IHttpCache& pCache);
            
            bool TryAddAsyncLoad(Payload *pPayload);
            void CancelLoad(Web::IWebLoadRequest& webLoadRequest);
            void OnWebLoadRequestComplete(Web::IWebResponse& webResponse);
            
            bool IsStreaming() const;
            
        private:
            int m_webRequests;
            int m_cacheRequests;
            int m_maxWebRequests;
            int m_maxCacheRequests;
            
            Eegeo::Helpers::IHttpCache& m_httpCache;
            Web::IWebLoadRequestFactory& m_webLoadRequestFactory;

            bool CanAcceptHttpLoads() const { return m_webRequests < m_maxWebRequests; }
            bool CanAcceptCacheLoads() const { return m_cacheRequests < m_maxCacheRequests; }
            void AddAsyncPayloadRequest(Payload* pPayload, bool isLocallyCached);

            void RemoveLoad(Payload* pPayload);
            
            Web::TWebLoadRequestCompletionCallback<PayloadWebLoader> m_requestCallback;
            Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;

        };
    }
}