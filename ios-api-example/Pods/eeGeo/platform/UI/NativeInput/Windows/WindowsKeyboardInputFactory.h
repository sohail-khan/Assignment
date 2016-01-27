// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "KeyboardInput.h"
#include "IKeyboardInputFactory.h"
#include "IWindowsInputHandler.h"
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
                class WindowsKeyboardInputFactory : public IKeyboardInputFactory
                {
                	WindowsNativeState* m_pState;
                	Eegeo::Windows::Input::IWindowsInputHandler& inputHandler;

                public:
                	WindowsKeyboardInputFactory(WindowsNativeState* pState, Eegeo::Windows::Input::IWindowsInputHandler& inputHandler) :
                	m_pState(pState),
                	inputHandler(inputHandler) {}

                    virtual ~WindowsKeyboardInputFactory() {}

                    virtual IKeyboardInput* CreateKeyboardInput(IKeyboardInputDismissedHandler& dismissedHandler,
                    											IKeyboardInputKeyPressedHandler& keyPressedHandler,
                    											KeyboardType keyboardType = KeyboardTypeDefault,
                    											ReturnKeyType returnKeyType = ReturnKeyDone);
                };
            }
        }
    }
}

