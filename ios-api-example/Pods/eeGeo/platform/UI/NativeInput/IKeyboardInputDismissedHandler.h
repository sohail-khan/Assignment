// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            class IKeyboardInputDismissedHandler
            {
            public:
                virtual ~IKeyboardInputDismissedHandler() {}
                
                virtual void HandleKeyboardInputDismissed() = 0;
            };
        }
    }
}
