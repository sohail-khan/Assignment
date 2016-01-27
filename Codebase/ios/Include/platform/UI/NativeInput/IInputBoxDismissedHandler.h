// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            class IInputBoxDismissedHandler
            {
            public:
                virtual ~IInputBoxDismissedHandler() {}
                
                virtual void HandleInputBoxDismissed(const std::string& input)=0;
            };
        }
    }
}
