// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "WindowsInput.h"
#include "AppInterface.h"

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class TouchGesture
			{
			private:
				IWindowsInputHandler* pHandler;

				void CreateTouchEventData(AppInterface::TouchData& data, const TouchInputEvent& event);

			public:
				TouchGesture(IWindowsInputHandler* pHandler);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);
			};
		}
	}
}
