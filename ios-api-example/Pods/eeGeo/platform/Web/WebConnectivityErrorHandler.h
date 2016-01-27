// Copyright eeGeo Ltd (2016), All Rights Reserved

#pragma once

#include "Web.h"
#include "AlertBox.h"
#include "IEegeoErrorHandler.h"
#include "ICallback.h"
#include "ISingleOptionAlertBoxDismissedHandler.h"
#include <string>

namespace Eegeo
{
    namespace Web
    {
        /*
         Type to observe the WebConnectivityValidator and handles invalid states.
         For most states it will simply notify you, but for Capitive Wifi portals it will kill 
         the app due to potentially unreliable caching + responses.
         */
        class WebConnectivityErrorHandler
        {
        public:
            
            WebConnectivityErrorHandler(WebConnectivityValidator& webConnectivityValidator,
                                        IEegeoErrorHandler* pErrorHandler,
                                        UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory);
            ~WebConnectivityErrorHandler();
            
            const bool AwaitingAlertBoxResponse() const { return m_handlingAlertBox; }
            
        private:
            
            void HandleConnectivityChanged();
            void NotifyWarning(const std::string& message);
            void NotifyFatalError(const std::string& message);
            void HandleWarningDismissed();
            void HandleFatalErrorDismissed();
            
            WebConnectivityValidator& m_webConnectivityValidator;
            IEegeoErrorHandler* m_pErrorHandler;
            UI::NativeAlerts::IAlertBoxFactory& m_alertBoxFactory;
            Helpers::TCallback0<WebConnectivityErrorHandler> m_connectivityChangedHandler;
            
            bool m_handlingAlertBox;
            
            UI::NativeAlerts::TSingleOptionAlertBoxDismissedHandler<WebConnectivityErrorHandler> m_warningDismissedHandler;
            UI::NativeAlerts::TSingleOptionAlertBoxDismissedHandler<WebConnectivityErrorHandler> m_errorDismissedHandler;
            
        };
    }
}