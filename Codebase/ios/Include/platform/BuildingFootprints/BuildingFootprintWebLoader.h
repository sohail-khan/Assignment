// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "BuildingFootprints.h"
#include "Web.h"
#include "WebLoadRequestCompletionCallback.h"
#include "BuildingFootprintWebLoaderResult.h"
#include "ICallback.h"
#include "PendingWebRequestsContainer.h"
#include <string>


namespace Eegeo
{
    namespace BuildingFootprints
    {
        class BuildingFootprintWebLoader : public Eegeo::NonCopyable
        {
        public:
            typedef Helpers::ICallback1<const BuildingFootprintWebLoaderResult> ICallback;
            
            BuildingFootprintWebLoader(Web::IWebLoadRequestFactory& webRequestFactory);
            
            void LoadFootprintResource(const std::string& url, ICallback& callback);
            
        private:
            void WebLoadCompletedHandler(Eegeo::Web::IWebResponse& webLoadResponse);

            Web::IWebLoadRequestFactory& m_webRequestFactory;
            Web::TWebLoadRequestCompletionCallback<BuildingFootprintWebLoader> m_webLoadCompletedHandler;
            Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
        };
    }
}
