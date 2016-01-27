// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AndroidInput.h"
#include "AppInterface.h"

namespace Eegeo
{
	namespace Android
	{
		namespace Input
		{
			class TouchGesture
			{
			private:
				IAndroidInputHandler* pHandler;

				void CreateTouchEventData(AppInterface::TouchData& data, const TouchInputEvent& event);

			public:
				TouchGesture(IAndroidInputHandler* pHandler);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);
			};
		}
	}
}
