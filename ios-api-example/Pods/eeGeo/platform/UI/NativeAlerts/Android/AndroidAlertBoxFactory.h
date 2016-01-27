// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "AlertBox.h"
#include "IAlertBoxFactory.h"
#include <string>
#include "AndroidNativeState.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            namespace Android
            {
                class AndroidAlertBoxFactory : public IAlertBoxFactory
                {
                	AndroidNativeState* m_pState;
                public:
                	AndroidAlertBoxFactory(AndroidNativeState* pState)
                	:m_pState(pState)
                	{ }

                    virtual ~AndroidAlertBoxFactory() {}

                    virtual ISingleOptionAlertBox* CreateSingleOptionAlertBox(const std::string& title,
                                                      	  	  	  	  	  	  const std::string& message,
                                                      	  	  	  	  	  	  ISingleOptionAlertBoxDismissedHandler& handler);
                };
            }
        }
    }
}


