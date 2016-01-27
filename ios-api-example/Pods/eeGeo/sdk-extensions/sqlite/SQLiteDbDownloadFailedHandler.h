// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "EegeoRootDeclarations.h"
#include "AlertBox.h"
#include "ISingleOptionAlertBoxDismissedHandler.h"

#include <string>

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteDbDownloadFailedHandler
        {
        public:
            SQLiteDbDownloadFailedHandler(Eegeo::UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                                          std::string alertBoxCaption,
                                          std::string alertBoxMessage);
            
            bool IsShowingErrorMessage() const;
            void ShowErrorMessage();
            
            
        private:
            void DialogClosed();

            
            Eegeo::UI::NativeAlerts::IAlertBoxFactory& m_alertBoxFactory;
            
            const std::string m_alertBoxCaption;
            const std::string m_alertBoxMessage;
            
            Eegeo::UI::NativeAlerts::TSingleOptionAlertBoxDismissedHandler<SQLiteDbDownloadFailedHandler> m_dialogClosedHandler;
            bool m_showingErrorMessage;
        };
    }
}