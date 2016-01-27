// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "IWebLoadRequestFactory.h"
#include "IWebLoadRequest.h"
#include "WebLoadRequestCompletionCallback.h"

namespace Eegeo
{
    namespace Web
    {
        class PlatformUserAgentWebRequestFactory : public IWebLoadRequestFactory, private NonCopyable
        {
        public:
            PlatformUserAgentWebRequestFactory(IWebLoadRequestFactory& decoratedFactory, const std::string& userAgent)
            : m_factory(decoratedFactory)
            , m_userAgent(userAgent)
            {

            }

            ~PlatformUserAgentWebRequestFactory()
            {

            }
            
            WebRequestBuilder Begin(const Eegeo::Web::HttpVerbs::Values httpVerb,
                                    const std::string& url,
                                    IWebLoadRequestCompletionCallback& callback)
            {
                return m_factory.Begin(httpVerb, url, callback).SetUserAgent(m_userAgent);
            }

        private:
            IWebLoadRequestFactory& m_factory;
            const std::string m_userAgent;
        };
    }
}

