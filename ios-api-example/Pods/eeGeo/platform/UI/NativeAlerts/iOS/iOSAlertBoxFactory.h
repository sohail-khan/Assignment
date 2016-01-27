// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IAlertBoxFactory.h"
#include "AlertBox.h"
#include <string>

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            namespace iOS
            {
                class iOSAlertBoxFactory : public IAlertBoxFactory
                {
                public:
                    virtual ~iOSAlertBoxFactory() {}
                    
                    virtual ISingleOptionAlertBox* CreateSingleOptionAlertBox(const std::string& title,
                                                                              const std::string& message,
                                                                              ISingleOptionAlertBoxDismissedHandler& handler);
                };
            }
        }
    }
}
