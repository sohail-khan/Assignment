// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "Web.h"
#include "WebPostData.h"
#include "Helpers.h"
#include "UrlHelpers.h"

#include <string>
#include <map>
#include <vector>

namespace Eegeo
{
	namespace Web
	{
        /*!
         * \brief Builder that can be used for WebRequest construction.
         */
        class WebRequestBuilder
        {
        public:
            WebRequestBuilder(
                    const TWebRequestId requestId,
                    Eegeo::Web::WebRequestService& webRequestService,
                    Helpers::IHttpCache& httpCache,
                    const Eegeo::Web::HttpVerbs::Values httpVerb,
                    const std::string& url,
                    IWebLoadRequestCompletionCallback& callback,
                    Helpers::UrlHelpers::IUrlEncoder& encoder);

            WebRequestBuilder& AddHeader(const std::string& headerFieldName, const std::string& value);
            
            WebRequestBuilder& AddFormData(const std::string& keyName, const std::string& value);
            WebRequestBuilder& AddPostData(const std::string& keyName, const WebPostData& postData);

            WebRequestBuilder& SetUserData(void* pUserData);
            WebRequestBuilder& SetUserAgent(const std::string& userAgent);
            WebRequestBuilder& SetRetryLimit(const u32 retryLimit);
            WebRequestBuilder& SetTimeout(const u32 timeoutInSeconds);
            
            WebRequestBuilder& SetShouldCacheAggressively(const bool shouldCacheAggressively);
            WebRequestBuilder& SetShouldRequestOnlyFromCache(const bool cacheOnly);
            
            WebRequestBuilder& AcceptContentType(const std::string& mimeType);
            WebRequestBuilder& RequireResponseHeader(const std::string& requiredHeaderName);

            Eegeo::Web::IWebLoadRequest* Build();
        private:
            bool TryAddConditionalGetHeaders();
            
            const Eegeo::Web::HttpVerbs::Values m_httpVerb;
            const std::string m_url;
            IWebLoadRequestCompletionCallback& m_callback;
            Helpers::UrlHelpers::IUrlEncoder& m_encoder;

            void* m_pUserData;
            std::string m_userAgent;
            int m_retryLimit;
            int m_timeoutInSeconds;
            std::map<std::string, std::string> m_httpRequestHeaders;
            std::map<std::string, WebPostData> m_httpPostData;
            std::vector<std::string> m_acceptableMimeTypes;
            std::vector<std::string> m_requiredResponseHeaderNames;

            const TWebRequestId m_requestId;
            Eegeo::Web::WebRequestService& m_webRequestService;
            Helpers::IHttpCache& m_httpCache;
            bool m_hasBeenBuilt;
            bool m_shouldCacheAggressively;
            bool m_cacheOnly;
        };
	}
}
