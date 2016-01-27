// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "InputBox.h"
#include "IInputBoxFactory.h"
#include <string>
#include "AndroidNativeState.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace Android
            {
                class AndroidInputBoxFactory : public IInputBoxFactory
                {
                	AndroidNativeState* m_pState;
                public:
                	AndroidInputBoxFactory(AndroidNativeState* pState)
                	:m_pState(pState)
                	{ }

                    virtual ~AndroidInputBoxFactory() {}

                    virtual IInputBox* CreateInputBox(const std::string& title,
                                                      const std::string& message,
                                                      const std::string& button,
                                                      const std::string& placeholder,
                                                      bool initialContentIsPlaceholder,
                                                      IInputBoxDismissedHandler& handler);
                };
            }
        }
    }
}


