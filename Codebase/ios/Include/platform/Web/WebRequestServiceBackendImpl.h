// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Web.h"
#include "Tasks.h"
#include "Helpers.h"
#include "Web.h"
#include "BidirectionalWebIOBus.h"
#include "WebMessages.h"
#include "WebIOConfig.h"

#include <curl.h>
#include <uv.h>

#include <string>
#include <deque>
#include <list>
#include <vector>

namespace Eegeo
{
	namespace Web
	{
		// we use this to marry up a curl socket & a uv poll handle
		struct AppCurlContext
		{
			// uv_poll_t must be the first field; do not re-order or it'll break everything!
			uv_poll_t pollHandle;
			curl_socket_t sockfd;
			void* data; // expect this to be an instance of WebRequestServiceBackendImpl
		};

		// pimpl class to avoid pulling in various headers & causing include chaos
        class WebRequestServiceBackendImpl : public Eegeo::NonCopyable
		{
		public:
			WebRequestServiceBackendImpl(const WebIOConfig& config, Eegeo::Web::TMessageBus& webMessageBus);

			~WebRequestServiceBackendImpl();

			bool Update();
        private:
            void StartWebRequest(InFlightWebRequest* request, Eegeo::Web::WebRequestHandle* requestHandle);
			void IssueWebLoadRequests();
            void SendResponse(InFlightWebRequest& completedWebRequest);
            void SendFallBackToCacheMessage(const TWebRequestId requestId);
			void CheckMultiInfo();

            void ResetHandle(WebRequestHandle* pWebRequestHandle);

			void OnWebPauseMessage(const Eegeo::Web::WebPauseMessage& message);
			void OnWebResumeMessage(const Eegeo::Web::WebResumeMessage& message);
            void OnWebRequestLoadMessage(const Eegeo::Web::WebRequestLoadMessage& message);
            void OnWebRequestCancelMessage(const Eegeo::Web::WebRequestCancelMessage& message);
            void OnWebStopWorkMessage(const Eegeo::Web::WebStopWorkMessage& message);

			// libcurl callbacks
			static int CurlSocketCallbackWrapper(CURL* easy, curl_socket_t s, int action, void* userp, void* socketp);
			int CurlSocketCallBack(CURL* easy, curl_socket_t s, int action, void* socketp);

			static int CurlTimeoutCallbackWrapper(CURLM* multi, long timeout_ms, void* userp);
			int CurlTimeoutCallback(CURLM* multi, long timeout_ms);

			// libuv callbacks
			// (static) callback that is invoked by libuv when changes are detected on a socket it is monitoring.
			static void UVCallbackPollWrapper(uv_poll_t* req, int status, int events);
			void UVCallbackPoll(AppCurlContext* pAppCurlContext, int status, int events);

			// (static) callback invoked by libuv when a timeout occurs
			static void UVCallbackTimeoutWrapper(uv_timer_t* handle);
			void UVCallbackTimeout(uv_timer_t* handle);

			const WebIOConfig m_config;
			int m_threadSleepDurationMilliseconds;
            Eegeo::Web::TMessageBus& m_webMessageBus;

            CURLM * m_curlMultiHandle;
            WebRequestHandlePool* m_pWebLoadHandlePool;
            std::vector<WebRequestHandle*> m_inFlightWebRequestHandles;
            std::list<InFlightWebRequest*> m_pendingWebRequests;

            int m_stillRunning;
            bool m_webLoadPoolExhaustedLastFrame;

			uv_timer_t m_uvTimer;
			uv_loop_t* m_pUvLoop;

            Eegeo::Helpers::TCallback1<WebRequestServiceBackendImpl, const WebPauseMessage&> m_webPauseMessageHandler;
            Eegeo::Helpers::TCallback1<WebRequestServiceBackendImpl, const WebResumeMessage&> m_webResumeMessageHandler;
            Eegeo::Helpers::TCallback1<WebRequestServiceBackendImpl, const WebRequestLoadMessage&> m_webRequestLoadMessageHandler;
            Eegeo::Helpers::TCallback1<WebRequestServiceBackendImpl, const WebRequestCancelMessage&> m_webRequestCancelMessageHandler;
            Eegeo::Helpers::TCallback1<WebRequestServiceBackendImpl, const WebStopWorkMessage&> m_webRequestStopWorkMessageHandler;

			bool m_continueRunning;
		};
	}
}
