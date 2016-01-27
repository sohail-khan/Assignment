// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Web.h"

#include <map>
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Web
    {
        typedef std::vector<Byte> TResourceData;
        
        
        struct WebLoadResponseStatistics
        {
        public:
            WebLoadResponseStatistics(const size_t bytesReadPreDecompress)
            : BytesReadPreDecompress(bytesReadPreDecompress)
            {
                
            }
            
            const size_t BytesReadPreDecompress;
        };
        
        
        class IWebLoadRequest
        {
        public:
            virtual ~IWebLoadRequest() { };
            
            virtual void Load() = 0;
            virtual void Cancel() = 0;

            virtual WebRequestService& GetWebRequestService() = 0;
            virtual HttpVerbs::Values GetHttpVerb() const = 0;
            virtual std::string GetUrl() const = 0;
            virtual IWebLoadRequestCompletionCallback& GetCallback() = 0;
            virtual void* GetUserData() = 0;
            virtual std::string GetUserAgent() const = 0;
            virtual int GetRetryLimit() const = 0;
            virtual int GetTimeoutInSeconds() const = 0;
            virtual const std::map<std::string, std::string>& GetHttpRequestHeaders() const = 0;
            virtual const std::map<std::string, WebPostData>& GetHttpPostData() const = 0;
            virtual TWebRequestId GetRequestId() const = 0;
            virtual bool ShouldCacheAggressively() const = 0;
            virtual bool CacheOnly() const = 0;
            virtual const std::vector<std::string>& GetAcceptableMimeTypes() const = 0;
            virtual const std::vector<std::string>& GetRequiredResponseHeaders() const = 0;
        };
        

        class IWebResponse
        {
        public:
            virtual ~IWebResponse() { };
            
            virtual bool IsSucceeded() const = 0;
            virtual bool IsErrored() const = 0;
            virtual bool IsCancelled() const = 0;
            virtual std::string GetUrl() const = 0;
            virtual HttpVerbs::Values GetHttpVerb() const = 0;
            virtual int GetHttpStatusCode() const = 0;
            virtual void* GetUserData() = 0;
            virtual const TResourceData& GetHeaderData() const = 0;
            virtual const TResourceData& GetBodyData() const = 0;
            virtual WebLoadResponseStatistics GetStatistics() const = 0;
            virtual bool MatchesRequestId(const TWebRequestId requestId) const = 0;
            virtual TWebRequestId GetRequestId() const = 0;

            // sole mutable method
            virtual const TResourceData* TransferResourceDataOwnership() = 0;
        };
    }
}
