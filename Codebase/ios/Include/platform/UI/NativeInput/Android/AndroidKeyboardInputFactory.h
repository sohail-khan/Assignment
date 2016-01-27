// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "KeyboardInput.h"
#include "IKeyboardInputFactory.h"
#include "IAndroidInputHandler.h"
#include <string>
#include "AndroidNativeState.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace Android
            {
                class AndroidKeyboardInputFactory : public IKeyboardInputFactory
                {
                	AndroidNativeState* m_pState;
                	Eegeo::Android::Input::IAndroidInputHandler& inputHandler;

                public:
                	AndroidKeyboardInputFactory(AndroidNativeState* pState, Eegeo::Android::Input::IAndroidInputHandler& inputHandler) :
                	m_pState(pState),
                	inputHandler(inputHandler) {}

                    virtual ~AndroidKeyboardInputFactory() {}

                    virtual IKeyboardInput* CreateKeyboardInput(IKeyboardInputDismissedHandler& dismissedHandler,
                    											IKeyboardInputKeyPressedHandler& keyPressedHandler,
                    											KeyboardType keyboardType = KeyboardTypeDefault,
                    											ReturnKeyType returnKeyType = ReturnKeyDone);
                };
            }
        }
    }
}

