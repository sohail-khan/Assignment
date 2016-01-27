// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "InputBox.h"
#include "IInputBoxFactory.h"
#include <string>
#include "WindowsNativeState.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace Windows
            {
                class WindowsInputBoxFactory : public IInputBoxFactory
                {
                	WindowsNativeState* m_pState;
                public:
                	WindowsInputBoxFactory(WindowsNativeState* pState)
                	:m_pState(pState)
                	{ }

                    virtual ~WindowsInputBoxFactory() {}

                    virtual IInputBox* CreateInputBox(const std::string& title,
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


