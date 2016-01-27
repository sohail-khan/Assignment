// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

#include "Types.h"
#include "Web.h"
#include "WebLoadRequestCompletionCallback.h"
#include "NativeUIFactories.h"
#include "IEegeoErrorHandler.h"
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Web
    {
        class ApiTokenValidator : protected Eegeo::NonCopyable
        {
        public:
            ApiTokenValidator
            (
             Eegeo::Web::IWebLoadRequestFactory& webLoadRequestFactory,
             Eegeo::UI::NativeUIFactories& nativeInputFactories,
             Eegeo::IEegeoErrorHandler* m_pErrorHandler
            );
            ~ApiTokenValidator();
            
            void Validate(const std::string& apiToken);
            bool IsValid() const;
            
        private:
            IWebLoadRequestFactory& m_webLoadRequestFactory;
            Eegeo::UI::NativeUIFactories& m_nativeInputFactories;
            Eegeo::IEegeoErrorHandler* m_pErrorHandler;
            bool m_isValid;
            TWebLoadRequestCompletionCallback<Eegeo::Web::ApiTokenValidator> m_apiValidationHandler;
            Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
            
            void ApiValidationHandler(Eegeo::Web::IWebResponse& webResponse);
        };
    }
}


