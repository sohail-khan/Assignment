// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "AlertBox.h"
#include "Web.h"
#include "ISingleOptionAlertBoxDismissedHandler.h"

namespace Eegeo
{
    class IEegeoErrorHandler;
    
    namespace Streaming
    {
        namespace CoverageTrees
        {
            class CoverageTreeDownloadFailedHandler : public Eegeo::NonCopyable
            {
            public:
                CoverageTreeDownloadFailedHandler(UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                                                  Web::IConnectivityService& connectivityService,
                                                  IEegeoErrorHandler* pErrorHandler);
                
                bool ShowingError();
                
                void ShowErrorMessage();
                
            private:
                Web::IConnectivityService& m_connectivityService;
                IEegeoErrorHandler* m_pErrorHandler;
                
                bool m_showingError;
                
                UI::NativeAlerts::IAlertBoxFactory& m_alertBoxFactory;
                
                UI::NativeAlerts::TSingleOptionAlertBoxDismissedHandler<CoverageTreeDownloadFailedHandler> m_failAlertHandler;
                
                void HandleErrorMessageBoxClosed();
            };
        }
    }
}