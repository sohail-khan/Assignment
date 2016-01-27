// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "KeyboardInput.h"
#include "IKeyboardInput.h"
#include <string>
#include "WindowsNativeState.h"

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class IWindowsInputHandler;
		}
	}

    namespace UI
    {
        namespace NativeInput
        {
            namespace Windows
            {
				class WindowsKeyboardInput : public IKeyboardInput
				{
					IKeyboardInputDismissedHandler &m_dismissedHandler;
					IKeyboardInputKeyPressedHandler &m_keyPressedHandler;
					Eegeo::Windows::Input::IWindowsInputHandler &inputHandler;
					WindowsNativeState *m_pState;
					bool m_closed;
					bool m_nativesRequireUnregistering;
					//jclass m_msgBoxClass;

				public:
					WindowsKeyboardInput(WindowsNativeState *pState,
							Eegeo::Windows::Input::IWindowsInputHandler &inputHandler,
							NativeInput::IKeyboardInputDismissedHandler& dismissedHandler,
							NativeInput::IKeyboardInputKeyPressedHandler& keyPressedHandler,
							NativeInput::KeyboardType keyboardType,
							NativeInput::ReturnKeyType returnKeyType);

					virtual ~WindowsKeyboardInput();

					virtual void Dismiss();
				};
            }
        }
    }
}

