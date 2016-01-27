// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AndroidInput.h"
#include "PanGesture.h"
#include "PinchGesture.h"
#include "RotateGesture.h"
#include "TouchGesture.h"
#include "TapGesture.h"

namespace Eegeo
{
	namespace Android
	{
		namespace Input
		{
			class AndroidInputProcessor
			{
			private:
				PanGesture m_pan;
				PinchGesture m_pinch;
				RotateGesture m_rotate;
				TouchGesture m_touch;
				TapGesture m_tap;

			public:
				AndroidInputProcessor(IAndroidInputHandler* pHandler, const float screenWidth, const float screenHeight);
				void HandleInput(const TouchInputEvent& event);
				void Update(float deltaSeconds);
			};
		}
	}
}
