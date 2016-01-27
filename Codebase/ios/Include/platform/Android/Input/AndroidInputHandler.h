// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IAndroidInputHandler.h"
#include "KeyboardInput.h"
#include "AppInterface.h"
#include <list>

namespace Eegeo
{
	namespace Android
	{
		namespace Input
		{
			class AndroidInputHandler : public IAndroidInputHandler
			{
			public:
				AndroidInputHandler();

				void Event_TouchRotate 			(const AppInterface::RotateData& data);
				void Event_TouchRotate_Start	(const AppInterface::RotateData& data);
				void Event_TouchRotate_End 		(const AppInterface::RotateData& data);

				void Event_TouchPinch 			(const AppInterface::PinchData& data);
				void Event_TouchPinch_Start 	(const AppInterface::PinchData& data);
				void Event_TouchPinch_End 		(const AppInterface::PinchData& data);

				void Event_TouchPan				(const AppInterface::PanData& data);
				void Event_TouchPan_Start		(const AppInterface::PanData& data);
				void Event_TouchPan_End 		(const AppInterface::PanData& data);

				void Event_TouchTap				(const AppInterface::TapData& data);
				void Event_TouchDoubleTap		(const AppInterface::TapData& data);

				void Event_TouchDown 			(const AppInterface::TouchData& data);
				void Event_TouchMove 			(const AppInterface::TouchData& data);
				void Event_TouchUp 				(const AppInterface::TouchData& data);

				bool Event_KeyPress(const AppInterface::KeyboardData& data);
				void AddKeyPressListener(Eegeo::UI::NativeInput::IKeyboardInputKeyPressedHandler* handler);
				bool RemoveKeyPressListener(Eegeo::UI::NativeInput::IKeyboardInputKeyPressedHandler* handler);

				void AddDelegateInputHandler(IAndroidInputHandler *delegate);
				bool RemoveDelegateInputHandler(IAndroidInputHandler *delegate);

				void SetViewportOffset(float x, float y);
				virtual float TranslateGlobalXToLocalX(float x);
				virtual	float TranslateGlobalYToLocalY(float y);

			private:
				float m_windowOffsetX;
				float m_windowOffsetY;
				std::list<Eegeo::Android::Input::IAndroidInputHandler*> inputHandlerDelegates;
				std::list<Eegeo::UI::NativeInput::IKeyboardInputKeyPressedHandler*> keyPressListeners;
			};
		}
	}
}
