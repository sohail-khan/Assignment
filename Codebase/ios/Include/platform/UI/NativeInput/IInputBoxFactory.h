// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "InputBox.h"
#include <string>

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            class IInputBoxFactory : public Eegeo::NonCopyable
            {
            public:
                virtual ~IInputBoxFactory() {}
                
                virtual IInputBox* CreateInputBox(const std::string& title,
                                                  const std::string& message,
                                                  const std::string& button,
                                                  const std::string& initialContent,
                                                  bool initialContentIsPlaceholder,
                                                  IInputBoxDismissedHandler& handler) = 0;
            };
        }
    }
}
