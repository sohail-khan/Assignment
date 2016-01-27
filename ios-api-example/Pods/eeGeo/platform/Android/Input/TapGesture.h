// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"
#include "AndroidInput.h"

namespace Eegeo
{
	namespace Android
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

				IAndroidInputHandler* m_pTapHandler;

				void DispatchSingleTap();
				void DispatchDoubleTap();
				bool WithinAnchorDeadzone(const TouchInputEvent& event) const;
				bool IsTapping() const;
				void Reset();
				void TrackPointerDown();
				void TrackPointerUp();
				bool NoPointerDown() const;

			public:
				TapGesture(IAndroidInputHandler* pTapHandler);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);

				void Update(float deltaSeconds);
			};
		}
	}
}
