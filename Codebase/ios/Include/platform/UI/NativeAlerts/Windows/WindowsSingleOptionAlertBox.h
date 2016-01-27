// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "WindowsNativeState.h"
#include "AlertBox.h"
#include "ISingleOptionAlertbox.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            namespace Windows
            {
                class WindowsSingleOptionAlertBox : public ISingleOptionAlertBox
                {
                	WindowsNativeState* m_pState;
                	ISingleOptionAlertBoxDismissedHandler& m_handler;
                    bool m_closed;
                    bool m_nativesRequireUnregistering;

                public:
                	WindowsSingleOptionAlertBox(
                			WindowsNativeState* pState,
                    		const std::string& title,
							const std::string& message,
							ISingleOptionAlertBoxDismissedHandler& handler);

                    virtual ~WindowsSingleOptionAlertBox();

                    virtual void Close();
                };
            }
        }
    }
}

