#pragma once

#include "Types.h"
#include "Web.h"
#include "IWebLoadRequest.h"
#include "WebPostData.h"
#include "WebProxySettings.h"

#include <map>
#include <string>


namespace Eegeo
{
    namespace Web
    {
        /*!
         * \brief An internal representation of a web request. This is not exposed to the user.
         *
         * Its responsibility is to store results as we receive header/body bytes over the wire.
         */
        class InFlightWebRequest : private Eegeo::NonCopyable
        {
        public:
            InFlightWebRequest(const TWebRequestId requestId,
                               const HttpVerbs::Values httpVerb,
                               const std::string& url,
                               const std::string& userAgent,
                               const int retryLimit,
                               const int timeoutInSeconds,
                               const std::map<std::string, std::string>& httpRequestHeaders,
                               const std::map<std::string, WebPostData>& httpPostData,
                               const std::vector<std::string>& acceptableMimeTypes,
                               const std::vector<std::string>& requiredResponseHeaders,
                               const WebProxySettings& proxySettings);
            
            ~InFlightWebRequest();
            
            TWebRequestId GetRequestId() const;
            HttpVerbs::Values GetHttpVerb() const;
            std::string GetUrl() const;
            std::string GetUserAgent() const;
            int GetRetryLimit() const;
            int GetTimeoutInSeconds() const;
            int GetHttpStatusCode() const;
            WebLoadResponseCompletionCode::Values GetCompletionCode() const;
            const std::map<std::string, std::string>& GetHttpRequestHeaders() const;
            const std::map<std::string, WebPostData>& GetHttpPostData() const;
            const std::vector<std::string>& GetAcceptableMimeTypes() const;
            const std::vector<std::string>& GetRequiredResponseHeaders() const;
            const WebProxySettings& GetProxySettings() const;
            
            bool CanRetry() const;
            bool HasCacheHeaders() const;

            const TResourceData& GetHeaderData() const;
            const TResourceData& GetBodyData() const;
            
            bool IsComplete() const;
            bool IsCancelled() const;
            size_t GetPreDecompressBytesRead() const;
            
            InFlightWebRequest* CreateRetryRequest() const;
            
            // mutable stuff
            void SetComplete(const int httpStatusCode, const WebLoadResponseCompletionCode::Values completionCode);
            void SetCancelled();
            void SetPreDecompressBytesRead(size_t numBytes);
            
            void AppendHeaderData(Byte* data, size_t size);
            void AppendBodyData(Byte* data, size_t size);
            void ReserveBodyDataCapacity(const size_t size);
            
            void TransferResourceDataOwnership(TResourceData*& outHeaderData, TResourceData*& outBodyData);
            
        private:
            const TWebRequestId m_requestId;
            const HttpVerbs::Values m_httpVerb;
            const std::string m_url;
            const std::string m_userAgent;
            const int m_retryLimit;
            const int m_timeoutInSeconds;
            const std::map<std::string, std::string> m_httpRequestHeaders;
            const std::map<std::string, WebPostData> m_httpPostData;
            const std::vector<std::string> m_acceptableMimeTypes;
            const std::vector<std::string> m_requiredResponseHeaders;
            const WebProxySettings m_proxySettings;
            
            bool m_isComplete;
            int m_httpStatusCode;
            WebLoadResponseCompletionCode::Values m_completionCode;
            
            bool m_isCancelled;
            size_t m_preDecompressBytesRead;
            
            TResourceData* m_pHeaderData;
            TResourceData* m_pBodyData;
        };
    }
}