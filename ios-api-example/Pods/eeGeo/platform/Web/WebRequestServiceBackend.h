// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include "Tasks.h"
#include "Web.h"
#include "BidirectionalWebIOBus.h"

namespace Eegeo
{
	namespace Web
	{
        class WebRequestServiceBackend : private Eegeo::NonCopyable
        {
        public:
            WebRequestServiceBackend(
                    const WebIOConfig& config,
                    Eegeo::Web::TMessageBus& webMessageBus);

            ~WebRequestServiceBackend();

            bool Update();
        private:
            Eegeo::Web::WebRequestServiceBackendImpl* m_pImpl;
        };
	}
}
