// Copyright eeGeo Ltd (2015), All Rights Reserved

#pragma once

#include "Web.h"
#include "WebPostData.h"
#include "WebProxySettings.h"
#include <string>
#include <map>

namespace Eegeo
{
    namespace Web
    {
        struct WebRequestDto
        {
        public:
            WebRequestDto(
                const TWebRequestId webRequestId,
                const HttpVerbs::Values httpVerb,
                const std::string& url,
                const std::string& userAgent,
                const int retryLimit,
                const int timeoutInSeconds,
                const std::map<std::string, std::string>& httpRequestHeaders,
                const std::map<std::string, WebPostData>& httpPostData,
                const std::vector<std::string>& acceptableMimeTypes,
                const std::vector<std::string>& requiredResponseHeaders,
                const WebProxySettings& webProxySettings)
            : WebRequestId(webRequestId)
            , HttpVerb(httpVerb)
            , Url(url)
            , UserAgent(userAgent)
            , RetryLimit(retryLimit)
            , TimeoutInSeconds(timeoutInSeconds)
            , HttpRequestHeaders(httpRequestHeaders)
            , HttpPostData(httpPostData)
            , AcceptableMimeTypes(acceptableMimeTypes)
            , RequiredResponseHeaders(requiredResponseHeaders)
            , ProxySettings(webProxySettings)
            {

            }

            const TWebRequestId WebRequestId;
            const HttpVerbs::Values HttpVerb;
            const std::string Url;
            const std::string UserAgent;
            const int RetryLimit;
            const int TimeoutInSeconds;
            const std::map<std::string, std::string> HttpRequestHeaders;
            const std::map<std::string, WebPostData> HttpPostData;
            const std::vector<std::string> AcceptableMimeTypes;
            const std::vector<std::string> RequiredResponseHeaders;
            const WebProxySettings ProxySettings;
        };
    }
}