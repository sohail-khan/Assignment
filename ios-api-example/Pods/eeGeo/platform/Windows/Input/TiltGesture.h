// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "WindowsInput.h"
#include "TouchEventWrapper.h"
#include "IWindowsInputHandler.h"

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class TiltGesture
			{
			private:
				IWindowsInputHandler* m_pHandler;
				bool m_tilting;
				float m_previousMousePositionY;

			public:
				TiltGesture(IWindowsInputHandler* pHandler);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event, float screenWidth, float screenHeight);
			};
		}
	}
}
