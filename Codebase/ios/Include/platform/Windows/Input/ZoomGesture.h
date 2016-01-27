// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"
#include "WindowsInput.h"

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class ZoomGesture
			{
			private:
				IWindowsInputHandler* m_pZoomHandler;

			public:
				ZoomGesture(IWindowsInputHandler* pZoomHandler);

				void PointerMove(const TouchInputEvent& event);
			};
		}
	}
}
