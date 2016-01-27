// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "IAlertBoxFactory.h"
#include "IInputBoxFactory.h"
#include "IKeyboardInputFactory.h"
#include "IKeyboardInputDismissedHandler.h"
#include "NativeUIFactories.h"

namespace Eegeo
{
    namespace OSX
    {
        class OSXAlertBoxFactory : public UI::NativeAlerts::IAlertBoxFactory
        {
            UI::NativeAlerts::ISingleOptionAlertBox* CreateSingleOptionAlertBox(const std::string& title,
                                                                      const std::string& message,
                                                                      UI::NativeAlerts::ISingleOptionAlertBoxDismissedHandler& handler)
            {
                return NULL;
            }
        };
        
        class OSXInputBoxFactory : public UI::NativeInput::IInputBoxFactory
        {
            UI::NativeInput::IInputBox* CreateInputBox(const std::string& title,
                                              const std::string& message,
                                              const std::string& button,
                                              const std::string& initialContent,
                                              bool initialContentIsPlaceholder,
                                              UI::NativeInput::IInputBoxDismissedHandler& handler)
            {
                return NULL;
            }
        };
        
        class OSXKeyboardInputFactory : public UI::NativeInput::IKeyboardInputFactory
        {
            UI::NativeInput::IKeyboardInput* CreateKeyboardInput(UI::NativeInput::IKeyboardInputDismissedHandler& dismissedHandler,
                                                                 UI::NativeInput::IKeyboardInputKeyPressedHandler& keyPressedHandler,
                                                                 UI::NativeInput::KeyboardType keyboardType = UI::NativeInput::KeyboardTypeDefault,
                                                                 UI::NativeInput::ReturnKeyType returnKeyType = UI::NativeInput::ReturnKeyDone)
            {
                return NULL;
            }

        };
    }
}