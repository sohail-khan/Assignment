// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Web.h"
#include "Types.h"
#include "WebRequestBuilder.h"
#include "IWebLoadRequestFactory.h"
#include "Helpers.h"
#include "UrlHelpers.h"

namespace Eegeo
{
	namespace Web
	{
        class WebLoadRequestFactory : public Eegeo::Web::IWebLoadRequestFactory, private Eegeo::NonCopyable
        {
        public:
        	WebLoadRequestFactory(Eegeo::Web::WebRequestService& webRequestService,
                                  Helpers::IHttpCache& httpCache,
                                  Helpers::UrlHelpers::IUrlEncoder& encoder);

            WebRequestBuilder Begin(
                    const Eegeo::Web::HttpVerbs::Values httpVerb,
                    const std::string& url,
                    IWebLoadRequestCompletionCallback& callback);

        private:
            
            TWebRequestId GetNextRequestId();
            
            Eegeo::Web::WebRequestService& m_webRequestService;
            Helpers::IHttpCache& m_httpCache;
            Helpers::UrlHelpers::IUrlEncoder& m_encoder;
        };

	}
}
