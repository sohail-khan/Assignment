// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Web.h"
#include "Cache.h"
#include "ICallback.h"
#include "Types.h"

#include <curl.h>
#include <string>

namespace Eegeo
{
	namespace Web
	{
		namespace WebHandleCompletionCode
		{
			enum Values
			{
				// Equivalent to HTTP 200 OK, full response returned.
				Success,

				// Equivalent to HTTP 304 Not Modified in response to conditional get.
				NotModified,

				// Request failed.
				Failed,

				Cancelled
			};
		}

		struct HandleCompletedResult
		{
			WebHandleCompletionCode::Values CompletionCode;
			bool CanFallBackToCache;
			bool RetryPossible;
			int HttpResponseCode;

			HandleCompletedResult()
			: CompletionCode(WebHandleCompletionCode::Failed)
			, CanFallBackToCache(false)
			, RetryPossible(false)
			, HttpResponseCode(0)
			{}
		};

        typedef int TWebRequestHandleId;

		class WebRequestHandle : private Eegeo::NonCopyable
		{
		public:
			WebRequestHandle(const TWebRequestHandleId handleId, const std::string& caCertFilePath);
			~WebRequestHandle();

			CURL* GetCurlHandle() const;
			bool IsInUse() const;
			std::string GetUrl() const;
            bool IsCancelled() const;

            // mutable
            void Use(InFlightWebRequest* pWebLoadRequest);
            
			void AppendBodyData(Byte* data, size_t size);
			void AppendHeaderData(Byte* data, size_t size);

			HandleCompletedResult HandleCompleted(CURLcode curlTransferReturnCode);

			InFlightWebRequest* GetInFlightWebRequest();
            TWebRequestHandleId GetHandleId() const;
            void Reset();
            
		private:

			void SetupCurlOptions();
			void WritePostData();
			void WriteMultipartFormData();
			void WriteMultipartFormField(curl_httppost** httpPost, const std::string& fieldName, const WebPostData& fieldData);
			void WriteMultipartFormText(curl_httppost** httpPost, const std::string& fieldName, const WebPostData& fieldData);
			void WriteMultipartFormBinary(curl_httppost** httpPost, const std::string& fieldName, const WebPostData& fieldData);
			void WriteHeaders();
            
            bool ValidateHeaders();

			const TWebRequestHandleId m_handleId;
			CURL* m_pHandle;
            curl_slist* m_pCurlHeaderChunk;
			curl_httppost* m_pCurlFormPost;

			InFlightWebRequest* m_pInFlightWebRequest;

			std::string m_caCertFilePath;
			bool m_caCertRequired;
		};
	}
}
