// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "KeyboardInput.h"
#include "IKeyboardInput.h"
#include <string>
#include "AndroidNativeState.h"

namespace Eegeo
{
	namespace Android
	{
		namespace Input
		{
			class IAndroidInputHandler;
		}
	}

    namespace UI
    {
        namespace NativeInput
        {
            namespace Android
            {
				class AndroidKeyboardInput : public IKeyboardInput
				{
					IKeyboardInputDismissedHandler &m_dismissedHandler;
					IKeyboardInputKeyPressedHandler &m_keyPressedHandler;
					Eegeo::Android::Input::IAndroidInputHandler &inputHandler;
					AndroidNativeState *m_pState;
					bool m_closed;
					bool m_nativesRequireUnregistering;
					jclass m_msgBoxClass;

				public:
					AndroidKeyboardInput(AndroidNativeState *pState,
							Eegeo::Android::Input::IAndroidInputHandler &inputHandler,
							IKeyboardInputDismissedHandler& dismissedHandler,
							IKeyboardInputKeyPressedHandler& keyPressedHandler,
							KeyboardType keyboardType,
							ReturnKeyType returnKeyType);

					virtual ~AndroidKeyboardInput();

					virtual void Dismiss();
				};
            }
        }
    }
}

