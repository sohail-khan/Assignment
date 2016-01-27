// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "KeyboardInput.h"
#include "IKeyboardInput.h"
#include <string>

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            class IKeyboardInputFactory : public Eegeo::NonCopyable
            {
            public:
                virtual ~IKeyboardInputFactory() {}
                
                virtual IKeyboardInput* CreateKeyboardInput(IKeyboardInputDismissedHandler& dismissedHandler,
                                                            IKeyboardInputKeyPressedHandler& keyPressedHandler,
                                                            KeyboardType keyboardType = KeyboardTypeDefault,
                                                            ReturnKeyType returnKeyType = ReturnKeyDone) = 0;
            };
        }
    }
}
