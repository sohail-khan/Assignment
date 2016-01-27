// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IInputBoxFactory.h"
#include "InputBox.h"
#include <string>

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace iOS
            {
                class iOSInputBox;
                
                class iOSInputBoxFactory : public IInputBoxFactory
                {
                public:
                    virtual ~iOSInputBoxFactory() {}
                    
                    virtual IInputBox* CreateInputBox(const std::string& title,
                                                      const std::string& message,
                                                      const std::string& button,
                                                      const std::string& placeholder,
                                                      bool initialContentIsPlaceholder,
                                                      IInputBoxDismissedHandler& handler);
                    
                    virtual iOSInputBox* CreateiOSInputBox(const std::string& title,
                                                           const std::string& message,
                                                           const std::string& button,
                                                           const std::string& placeholder,
                                                           bool initialContentIsPlaceholder,
                                                           IInputBoxDismissedHandler& handler);
                };
            }
        }
    }
}