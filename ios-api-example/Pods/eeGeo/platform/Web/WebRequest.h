// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Web.h"
#include "Types.h"
#include "IWebLoadRequest.h"
#include "WebPostData.h"

#include <string>
#include <vector>
#include <map>

namespace Eegeo
{
    namespace Web
    {
        /*!
         * \brief A (largely) immutable class that represents a user-facing web request.
         *
         * Its sole responsibility is to allow the user to enqueue or cancel the request.
         * We should avoid mutating this, or adding more mutable fields.
         */
        class WebRequest : public IWebLoadRequest, private Eegeo::NonCopyable
        {
        public:
            
            WebRequest(
                    const TWebRequestId requestId,
                    Eegeo::Web::WebRequestService& m_webRequestService,
                    const HttpVerbs::Values httpVerb,
                    const std::string& url,
                    IWebLoadRequestCompletionCallback& callback,
                    void* const pUserData,
                    const std::string& userAgent,
                    const int retryLimit,
                    const int timeoutInSeconds,
                    const std::map<std::string, std::string> httpRequestHeaders,
                    const std::map<std::string, WebPostData> httpPostData,
                    const bool shouldCacheAggressively,
                    const bool cacheOnly,
                    const std::vector<std::string>& acceptableMimeTypes,
                    const std::vector<std::string>& requiredResponseHeaders);

            ~WebRequest();

            // mutate
            void Load();
            void Cancel();

            // immutable
            WebRequestService& GetWebRequestService();
            HttpVerbs::Values GetHttpVerb() const;
            std::string GetUrl() const;
            IWebLoadRequestCompletionCallback& GetCallback();
            void* GetUserData();
            std::string GetUserAgent() const;
            int GetRetryLimit() const;
            int GetTimeoutInSeconds() const;
            const std::map<std::string, std::string>& GetHttpRequestHeaders() const;
            const std::map<std::string, WebPostData>& GetHttpPostData() const;
            TWebRequestId GetRequestId() const;
            bool ShouldCacheAggressively() const;
            bool CacheOnly() const;
            const std::vector<std::string>& GetAcceptableMimeTypes() const;
            const std::vector<std::string>& GetRequiredResponseHeaders() const;
            
        private:
            // immutable
            const TWebRequestId m_requestId;
            const HttpVerbs::Values m_httpVerb;
            const std::string m_url;
            IWebLoadRequestCompletionCallback& m_callback;
            void* const m_pUserData;
            const std::string m_userAgent;
            const int m_retryLimit;
            const int m_timeoutInSeconds;
            const std::map<std::string, std::string> m_httpRequestHeaders;
            const std::map<std::string, WebPostData> m_httpPostData;
            const bool m_shouldCacheAggressively;
            const bool m_cacheOnly;
            const std::vector<std::string> m_acceptableMimeTypes;
            const std::vector<std::string> m_requiredResponseHeaders;

            Eegeo::Web::WebRequestService& m_webRequestService;

            // mutable
            bool m_cancelIssued;
            bool m_loadIssued;
        };
    }
}
