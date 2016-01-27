// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#include "InputBox.h"
#include "IInputBox.h"
#include "iOSKeyboardLocationObserver.h"

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
            }
        }
    }
}

@interface iOSInputBox_AlertHandler : UIViewController <UIAlertViewDelegate>{
    Eegeo::UI::NativeInput::iOS::iOSInputBox* pBox;
}
- (void)setBox:(Eegeo::UI::NativeInput::iOS::iOSInputBox*) box;
@end

struct iOSInputBox_AlertHandlerImpl
{
    iOSInputBox_AlertHandler* pClass;
};

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace iOS
            {
                class iOSInputBox : public IInputBox
                {
                    iOSInputBox_AlertHandlerImpl* m_pImpl;
                    iOSKeyboardInput_LocationObserverImpl* m_pLocationObserverImpl;
                    IInputBoxDismissedHandler& m_handler;
                    UIAlertView * m_alert;
                    bool m_closed;
                public:
                    iOSInputBox(const std::string& title,
                                const std::string& message,
                                const std::string& button,
                                const std::string& initialContent,
                                bool initialContentIsPlaceholder,
                                IInputBoxDismissedHandler& handler);
                    
                    virtual ~iOSInputBox();
                    
                    void DismissWithInput(const std::string& input);
                    
                    virtual void Close();
                    
                    iOSInputBox* Show();
                    
                    iOSInputBox* SetLocationChangedObserver(Eegeo::UI::NativeInput::IKeyboardLocationObserver* pObserver);
                };
            }
        }
    }
}
