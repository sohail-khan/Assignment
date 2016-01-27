// Copyright eeGeo Ltd (2015), All Rights Reserved

#pragma once

#include "Web.h"
#include "IWebLoadRequest.h"
#include <string>

namespace Eegeo
{
    namespace Web
    {
        struct WebResponseDto
        {
        public:
            WebResponseDto(
                const TWebRequestId webRequestId,
                const std::string& url,
                const int httpStatusCode,
                const WebLoadResponseCompletionCode::Values completionCode,
                const TResourceData* headerData,
                const TResourceData* bodyData,
                const WebLoadResponseStatistics& statistics)
            : WebRequestId(webRequestId)
            , Url(url)
            , HttpStatusCode(httpStatusCode)
            , CompletionCode(completionCode)
            , HeaderData(headerData)
            , BodyData(bodyData)
            , Statistics(statistics)
            {

            }

            const TWebRequestId WebRequestId;
            const std::string Url;
            const int HttpStatusCode;
            const WebLoadResponseCompletionCode::Values CompletionCode;
            const TResourceData* const HeaderData;
            const TResourceData* const BodyData;
            const WebLoadResponseStatistics Statistics;
        };
    }
}