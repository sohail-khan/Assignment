// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#include "IKeyboardInput.h"
#include "KeyboardInput.h"
#include "iOSKeyboardLocationObserver.h"
#include "AppInterface.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace iOS
            {
                class iOSKeyboardInput;
            }
        }
    }
}

@interface iOSKeyboardInput_TextHandler : UIViewController <UITextViewDelegate> {
    Eegeo::UI::NativeInput::iOS::iOSKeyboardInput* pKeyboard;
}

- (void)setKeyboard:(Eegeo::UI::NativeInput::iOS::iOSKeyboardInput*) keyboard;

@end

struct iOSKeyboardInput_TextHandlerImpl
{
    iOSKeyboardInput_TextHandler* pClass;
};

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace iOS
            {
                class iOSKeyboardInput : public IKeyboardInput
                {
                    iOSKeyboardInput_TextHandlerImpl* m_pImpl;
                    iOSKeyboardInput_LocationObserverImpl* m_pLocationObserverImpl;
                    IKeyboardInputDismissedHandler& m_dismissedHandler;
                    IKeyboardInputKeyPressedHandler& m_keyPressedHandler;
                    UITextView* m_textBox;
                    bool m_closed;
                    
                public:
                    iOSKeyboardInput(IKeyboardInputDismissedHandler& dismissedHandler,
                                     IKeyboardInputKeyPressedHandler& keyPressedHandler,
                                     KeyboardType keyboardType,
                                     ReturnKeyType returnKeyType);
                    
                    ~iOSKeyboardInput();
                    
                    void HandleKeyPressed(const AppInterface::KeyboardData& data);
                    
                    void Dismiss();
                    
                    iOSKeyboardInput* Show();
                    
                    iOSKeyboardInput* SetLocationChangedObserver(Eegeo::UI::NativeInput::IKeyboardLocationObserver* pObserver);
                };
            }
        }
    }
}
