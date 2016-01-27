// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "EegeoUI.h"
#include "AlertBox.h"
#include "InputBox.h"
#include "KeyboardInput.h"

namespace Eegeo
{
    namespace UI
    {
        class NativeUIFactories
        {
        public:
            NativeUIFactories(NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                              NativeInput::IInputBoxFactory& inputBoxFactory,
                              NativeInput::IKeyboardInputFactory& keyboardInputFactory)
            : m_alertBoxFactory(alertBoxFactory)
            , m_inputBoxFactory(inputBoxFactory)
            , m_keyboardInputFactory(keyboardInputFactory)
            {
                
            }
            
            NativeAlerts::IAlertBoxFactory& AlertBoxFactory() { return m_alertBoxFactory; };
            NativeInput::IInputBoxFactory& IInputBoxFactory() { return m_inputBoxFactory; };
            NativeInput::IKeyboardInputFactory& IKeyboardInputFactory() { return m_keyboardInputFactory; };
            
        private:
            NativeAlerts::IAlertBoxFactory& m_alertBoxFactory;
            NativeInput::IInputBoxFactory& m_inputBoxFactory;
            NativeInput::IKeyboardInputFactory& m_keyboardInputFactory;
        };
    }
}
