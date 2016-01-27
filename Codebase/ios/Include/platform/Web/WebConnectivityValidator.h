// Copyright eeGeo Ltd (2015), All Rights Reserved

#pragma once

#include "Web.h"
#include "IWebLoadRequest.h"
#include "ICallback.h"
#include "WebLoadRequestCompletionCallback.h"
#include "PendingWebRequestsContainer.h"
#include "CallbackCollection.h"
#include <string>

namespace Eegeo
{
    namespace Web
    {
        namespace WebConnectivityStates
        {
            enum VALUES
            {
                Unknown = 0,
                Offline,
                Validating,
                Portal,
                Online
            };
        }
        
        /*
         Validates the current web connectivity by calling a known response.  This may be invalid due to no connection
         enabled, or due to captive portal redirects.
        */
        class WebConnectivityValidator
        {
        public:
            
            WebConnectivityValidator(IConnectivityService& connectivityService,
                                     IWebLoadRequestFactory& webRequestFactory);
            ~WebConnectivityValidator();
            
            void PerformValidation();
            
            const WebConnectivityStates::VALUES GetCurrentState() const { return m_validationState; }
            const bool IsValid() const { return m_validationState == WebConnectivityStates::Online; }
            const bool IsValidating() const { return m_validationState == WebConnectivityStates::Validating; }
            
            void RegisterStateChangedCallback(Helpers::ICallback0& callback);
            void UnregisterStateChangedCallback(Helpers::ICallback0& callback);
            
        private:
            
            void HandleConnectionChanged(const bool &connected);
            void HandleCaptivePortalCheckResponse(IWebResponse& webResponse);
            void SetState(WebConnectivityStates::VALUES state);
            
            IConnectivityService& m_connectivityService;
            IWebLoadRequestFactory& m_webRequestFactory;
            PendingWebRequestsContainer m_pendingWebRequestsContainer;
            
            Helpers::TCallback1<WebConnectivityValidator, const bool&> m_connectionChangedCallback;
            TWebLoadRequestCompletionCallback<WebConnectivityValidator> m_captivePortalCheckCallback;
            WebConnectivityStates::VALUES m_validationState;
            
            Helpers::CallbackCollection0 m_stateChangedCallbacks;
        };
    }
}