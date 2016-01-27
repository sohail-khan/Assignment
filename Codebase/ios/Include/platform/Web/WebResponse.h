// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Web.h"
#include "Types.h"
#include "IWebLoadRequest.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Web
    {
        /*!
         * \brief A (largely immutable) class that represents the user-facing result of a WebLoadRequest.
         *
         * We should avoid mutating this, or adding mutable fields. It represents a response (a result) and nothing more.
         */
        class WebResponse : public Eegeo::Web::IWebResponse, private Eegeo::NonCopyable
        {
        public:
            WebResponse(
                    const TWebRequestId requestId,
                    const WebLoadResponseStatistics& statistics,
                    const std::string& url,
                    const HttpVerbs::Values httpVerb,
                    const int httpStatusCode,
                    void* const pUserData,
                    const TResourceData* bodyData,
                    const TResourceData* headerData,
                    const WebLoadResponseCompletionCode::Values completionCode);

            ~WebResponse();

            bool IsSucceeded() const;
            bool IsErrored() const;
            bool IsCancelled() const;

            std::string GetUrl() const;
            HttpVerbs::Values GetHttpVerb() const;
            int GetHttpStatusCode() const;
            void* GetUserData();
            const TResourceData& GetHeaderData() const;
            const TResourceData& GetBodyData() const;
            WebLoadResponseStatistics GetStatistics() const;
            bool MatchesRequestId(const TWebRequestId requestId) const;
            TWebRequestId GetRequestId() const;

            // sole mutable method
            const TResourceData* TransferResourceDataOwnership();
            
        private:
            const TWebRequestId m_requestId;
            
            const WebLoadResponseStatistics m_statistics;
            const std::string m_url;
            const HttpVerbs::Values m_httpVerb;
            const int m_httpStatusCode;
            void* const m_pUserData;

            // sole pieces of mutable data. We either own their lifetime (they're non-NULL), or the caller has grabbed them (NULL).
            const TResourceData* m_pBodyData;
            const TResourceData* m_pHeaderData;

            const WebLoadResponseCompletionCode::Values m_completionCode;
        };
    }
}
