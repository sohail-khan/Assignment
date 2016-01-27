// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "AlertBox.h"
#include "ISingleOptionAlertBoxDismissedHandler.h"

namespace Eegeo
{
    class IEegeoErrorHandler;
    
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemesMissingDataHandler : protected Eegeo::NonCopyable
            {
            public:
                CityThemesMissingDataHandler(IEegeoErrorHandler* pErrorHandler,
                                             UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory);
                
                bool ShowingError() const;
                void ShowErrorMessage();
            private:
                IEegeoErrorHandler* m_pErrorHandler;
                UI::NativeAlerts::IAlertBoxFactory& m_alertBoxFactory;
                UI::NativeAlerts::TSingleOptionAlertBoxDismissedHandler<CityThemesMissingDataHandler> m_failAlertHandler;
                
                bool m_showingErrorMessage;
                
                void HandleErrorMessageBoxClosed();
            };
        }
    }
}