// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "WindowsInput.h"

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class PinchGesture
			{
			private:
				IWindowsInputHandler* pHandler;
				bool pinching;
				float previousDistance;
				const float majorScreenDimension;

				bool UpdatePinching(bool pinching, const TouchInputEvent& event, float& pinchScale, int numTouches, bool pointerUp);

			public:
				PinchGesture(IWindowsInputHandler* pHandler, const float screenWidth, const float screenHeight);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);
			};
		}
	}
}
