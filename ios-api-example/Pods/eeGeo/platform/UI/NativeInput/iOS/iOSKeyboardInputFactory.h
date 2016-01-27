// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IKeyboardInputFactory.h"
#include "IKeyboardInput.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace iOS
            {
                class iOSKeyboardInput;
                
                class iOSKeyboardInputFactory : public IKeyboardInputFactory
                {
                public:
                    virtual ~iOSKeyboardInputFactory() {}
                    
                    virtual IKeyboardInput* CreateKeyboardInput(IKeyboardInputDismissedHandler& dismissedHandler,
                                                                IKeyboardInputKeyPressedHandler& keyPressedHandler,
                                                                KeyboardType keyboardType,
                                                                ReturnKeyType returnKeyType);
                    
                    virtual iOSKeyboardInput* CreateiOSKeyboardInput(IKeyboardInputDismissedHandler& dismissedHandler,
                                                                     IKeyboardInputKeyPressedHandler& keyPressedHandler,
                                                                     KeyboardType keyboardType,
                                                                     ReturnKeyType returnKeyType);
                };
            }
        }
    }
}