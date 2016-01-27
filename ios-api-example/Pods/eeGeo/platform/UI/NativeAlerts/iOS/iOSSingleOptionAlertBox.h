// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#include "AlertBox.h"
#include "ISingleOptionAlertBox.h"

#include <string>

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            namespace iOS
            {
                class iOSSingleOptionAlertBox;
            }
        }
    }
}

@interface iOSSingleOptionAlertBox_AlertHandler : UIViewController <UIAlertViewDelegate>{
    Eegeo::UI::NativeAlerts::iOS::iOSSingleOptionAlertBox* pBox;
}
- (void)setBox:(Eegeo::UI::NativeAlerts::iOS::iOSSingleOptionAlertBox*) box;
@end

struct iOSSingleOptionAlertBox_AlertHandlerImpl
{
    iOSSingleOptionAlertBox_AlertHandler* pClass;
};

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            namespace iOS
            {
                class iOSSingleOptionAlertBox : public ISingleOptionAlertBox
                {
                    iOSSingleOptionAlertBox_AlertHandlerImpl* m_pImpl;
                    ISingleOptionAlertBoxDismissedHandler& m_handler;
                    UIAlertView * m_alert;
                    bool m_closed;
                public:
                    iOSSingleOptionAlertBox(const std::string& title,
                                            const std::string& message,
                                            ISingleOptionAlertBoxDismissedHandler& handler);
                    
                    virtual ~iOSSingleOptionAlertBox();
                    
                    void Dismiss();
                    
                    virtual void Close();
                };
            }
        }
    }
}
