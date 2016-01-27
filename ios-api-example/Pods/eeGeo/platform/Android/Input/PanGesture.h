// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"
#include "VectorMath.h"
#include "AndroidInput.h"
#include <vector>

namespace Eegeo
{
	namespace Android
	{
		namespace Input
		{
			class PanGesture
			{
			private:
				IAndroidInputHandler* pHandler;
				bool panning;
				std::vector<Eegeo::v2> inputs;
				Eegeo::v2 panCenter;
				Eegeo::v2 panAnchor;
				const float majorScreenDimension;

				Eegeo::v2 GetTouchExtents(const TouchInputEvent& event) const;
				void PopulatePanData(int numTouches, const v2& touchExtents, AppInterface::PanData& out_panData) const;

			public:
				PanGesture(IAndroidInputHandler* pHandler, const float screenWidth, const float screenHeight);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);
			};
		}
	}
}
