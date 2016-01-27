// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "AlertBox.h"
#include <string>

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            class IAlertBoxFactory : public Eegeo::NonCopyable
            {
            public:
                virtual ~IAlertBoxFactory() {}
                
                virtual ISingleOptionAlertBox* CreateSingleOptionAlertBox(const std::string& title,
                                                                          const std::string& message,
                                                                          ISingleOptionAlertBoxDismissedHandler& handler) = 0;
            };
        }
    }
}