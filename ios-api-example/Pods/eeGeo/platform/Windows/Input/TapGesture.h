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
			class TapGesture
			{
			private:
				int m_tapDownCount;
				int m_tapUpCount;
				int m_currentPointerTrackingStack;
				float m_tapAnchorX;
				float m_tapAnchorY;
				long long m_tapUnixTime;

				IWindowsInputHandler* m_pTapHandler;

				void DispatchSingleTap();
				void DispatchDoubleTap();
				bool WithinAnchorDeadzone(const TouchInputEvent& event) const;
				bool IsTapping() const;
				void Reset();
				void TrackPointerDown();
				void TrackPointerUp();
				bool NoPointerDown() const;

			public:
				TapGesture(IWindowsInputHandler* pTapHandler);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);

				void Update(float deltaSeconds);
			};
		}
	}
}
