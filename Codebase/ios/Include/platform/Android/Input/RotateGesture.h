// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "AndroidInput.h"

namespace Eegeo
{
	namespace Android
	{
		namespace Input
		{
			class RotateGesture
			{
			private:
				IAndroidInputHandler* pHandler;
				bool rotating;
				Eegeo::v2 lastPointer[2];
				float lastRotationRadians;
				float m_totalRotation;
				float m_previousRotationDelta;

				bool needNewBaseline;

				Eegeo::v2 m_baselineDirection;

				const float m_majorScreenDimension;

				bool UpdateRotation(const TouchInputEvent& event, int numTouches, bool pointerUp);

			public:
				RotateGesture(IAndroidInputHandler* pHandler, float screenWidth, float screenHeight);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);
			};
		}
	}
}
