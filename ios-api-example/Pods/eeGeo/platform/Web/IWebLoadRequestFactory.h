// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Web.h"

// TODO: cleanup callsites or move WRB declaration into this file. Doing this to temporarily avoid breaking changes.
#include "WebRequestBuilder.h"

#include <string>

namespace Eegeo
{
    namespace Web
    {
        class IWebLoadRequestFactory
        {
        public:
            virtual WebRequestBuilder Begin(
                    const Eegeo::Web::HttpVerbs::Values httpVerb,
                    const std::string& url,
                    IWebLoadRequestCompletionCallback& callback) = 0;

            virtual ~IWebLoadRequestFactory() { };
        };
    }
}