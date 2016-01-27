// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>

namespace Eegeo
{
	namespace Android
	{
		namespace Input
		{
			struct TouchInputPointerEvent
			{
				float x, y;
				int pointerIdentity;
				int pointerIndex;

				TouchInputPointerEvent(float x, float y, int pointerIdentity, int pointerIndex)
					:x(x), y(y), pointerIdentity(pointerIdentity), pointerIndex(pointerIndex)
				{

				}
			};

			struct TouchInputEvent
			{
				bool isPointerUpEvent;
				bool isPointerDownEvent;
				int primaryActionIndex;
				int primaryActionIdentifier;
				std::vector<TouchInputPointerEvent> pointerEvents;

				TouchInputEvent(
						bool isPointerUpEvent,
						bool isPointerDownEvent,
						int primaryActionIndex,
						int primaryActionIdentifier)
					:isPointerUpEvent(isPointerUpEvent)
					,isPointerDownEvent(isPointerDownEvent)
					,primaryActionIndex(primaryActionIndex)
					,primaryActionIdentifier(primaryActionIdentifier)
				{

				}
			};
		}
	}
}
