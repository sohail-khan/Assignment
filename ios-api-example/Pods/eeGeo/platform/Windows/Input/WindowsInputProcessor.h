// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "WindowsInput.h"
#include "PanGesture.h"
#include "RotateGesture.h"
#include "ZoomGesture.h"
#include "TiltGesture.h"
#include "TouchGesture.h"
#include "TapGesture.h"
#include "WindowsNativeState.h"
#include "TouchEventWrapper.h"
#include "IWindowsInputHandler.h"

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class WindowsInputProcessor
			{
			private:
				PanGesture m_pan;
				ZoomGesture m_zoom;
				RotateGesture m_rotate;
				TiltGesture m_tilt;
				TouchGesture m_touch;
				TapGesture m_tap;

				EGLNativeWindowType m_hwnd;

                IWindowsInputHandler* m_pHandler;

			public:
				WindowsInputProcessor(IWindowsInputHandler* pHandler, EGLNativeWindowType hwnd, const float screenWidth, const float screenHeight);
				void HandleInput(const TouchInputEvent& event, float screenWidth, float screenHeight);
                void HandleInput(const KeyboardInputEvent& keyEvent);
				void Update(float deltaSeconds);

				bool IsMouseInsideWindow();
				void SetAllInputEventsToPointerUp(int x, int y);
			};
		}
	}
}
