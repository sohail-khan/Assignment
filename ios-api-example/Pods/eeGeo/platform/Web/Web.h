// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace Web
    {
        namespace HttpVerbs
        {
            enum Values
            {
                GET = 0,
                POST
            };
        }

        namespace WebLoadResponseCompletionCode
        {
            enum Values
            {
                Incomplete = 0,
                Success,
                Failed,
                Cancelled
            };
        }
        
        typedef int TWebRequestId;

        class ApiTokenValidator;
        class IConnectivityService;
        class InFlightWebRequest;
        class IWebLoadRequest;
        class IWebLoadRequestCompletionCallback;
        class IWebLoadRequestFactory;
        class IWebResponse;
        class PendingWebRequestsContainer;
        class PrecacheService;

        class WebLoadRequestFactory;
        class WebModule;
        class WebPostData;
        class WebRequest;
        class WebRequestBuilder;
        class WebRequestHandle;
        class WebRequestHandlePool;
        class WebRequestService;
        class WebRequestServiceBackend;
        class WebRequestServiceBackendImpl;
        class WebRequestServiceBackendRunner;
        class WebResponse;
        
        class WebConnectivityValidator;
        class WebConnectivityErrorHandler;
        
        struct WebIOConfig;
        struct WebLoadResponseStatistics;
        struct WebRequestDto;
        struct WebResponseDto;
        
        class IWebProxySettings;
    }
}
