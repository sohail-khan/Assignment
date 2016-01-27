// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            class IKeyboardInputKeyPressedHandler
            {
            public:
                virtual ~IKeyboardInputKeyPressedHandler() {}
                
                virtual bool HandleKeyboardInputKeyPressed(const AppInterface::KeyboardData& data) = 0;
            };
        }
    }
}
