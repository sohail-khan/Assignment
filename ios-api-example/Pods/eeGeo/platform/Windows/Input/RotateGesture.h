// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "WindowsInput.h"

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class RotateGesture
			{
			private:
				IWindowsInputHandler* pHandler;

				bool m_rotating;

				float m_previousMousePositionX;
				float m_totalRotation;
			public:
				RotateGesture(IWindowsInputHandler* pHandler);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);
			};
		}
	}
}
