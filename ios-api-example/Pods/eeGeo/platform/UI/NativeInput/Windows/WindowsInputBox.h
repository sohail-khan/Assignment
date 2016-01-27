// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "WindowsNativeState.h"
#include "InputBox.h"
#include "IInputBox.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace Windows
            {
                class WindowsInputBox : public IInputBox
                {
                	WindowsNativeState* m_pState;
                    IInputBoxDismissedHandler& m_handler;
                    bool m_closed;
                    bool m_nativesRequireUnregistering;

                public:
                    WindowsInputBox(
                    		WindowsNativeState* pState,
                    		const std::string& title,
							const std::string& message,
							const std::string& button,
							const std::string& initialContent,
							bool initialContentIsPlaceholder,
							IInputBoxDismissedHandler& handler);

                    virtual ~WindowsInputBox();

                    virtual void Close();
                };
            }
        }
    }
}

