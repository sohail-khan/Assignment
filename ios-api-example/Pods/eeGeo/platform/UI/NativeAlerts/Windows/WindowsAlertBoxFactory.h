// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "AlertBox.h"
#include "IAlertBoxFactory.h"
#include <string>
#include "WindowsNativeState.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            namespace Windows
            {
                class WindowsAlertBoxFactory : public IAlertBoxFactory
                {
                	WindowsNativeState* m_pState;
                public:
                	WindowsAlertBoxFactory(WindowsNativeState* pState)
                	:m_pState(pState)
                	{ }

                    virtual ~WindowsAlertBoxFactory() {}

                    virtual ISingleOptionAlertBox* CreateSingleOptionAlertBox(const std::string& title,
                                                      	  	  	  	  	  	  const std::string& message,
                                                      	  	  	  	  	  	  ISingleOptionAlertBoxDismissedHandler& handler);
                };
            }
        }
    }
}


