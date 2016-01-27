// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#include "KeyboardInput.h"

@interface iOSKeyboardInput_LocationObserver : UIViewController <UITextViewDelegate> {
    Eegeo::UI::NativeInput::IKeyboardLocationObserver* pObserver;
};

- (void)setObserver:(Eegeo::UI::NativeInput::IKeyboardLocationObserver*) observer;

@end

struct iOSKeyboardInput_LocationObserverImpl
{
    iOSKeyboardInput_LocationObserver* pClass;
};
