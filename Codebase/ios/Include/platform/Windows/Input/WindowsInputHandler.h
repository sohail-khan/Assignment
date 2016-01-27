// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IWindowsInputHandler.h"
#include "KeyboardInput.h"
#include "AppInterface.h"
#include <list>

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class WindowsInputHandler : public IWindowsInputHandler
			{
			public:
				WindowsInputHandler();

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
				void Event_Zoom					(const AppInterface::ZoomData& data);

				void Event_TiltStart			(const AppInterface::TiltData& data);
				void Event_TiltEnd				(const AppInterface::TiltData& data);
				void Event_Tilt					(const AppInterface::TiltData& data);

				bool Event_KeyPress(const AppInterface::KeyboardData& data);
				void AddKeyPressListener(Eegeo::UI::NativeInput::IKeyboardInputKeyPressedHandler* handler);
				bool RemoveKeyPressListener(Eegeo::UI::NativeInput::IKeyboardInputKeyPressedHandler* handler);

				void AddDelegateInputHandler(IWindowsInputHandler *_delegate);
				bool RemoveDelegateInputHandler(IWindowsInputHandler *_delegate);

				void SetViewportOffset(float x, float y);
				virtual float TranslateGlobalXToLocalX(float x);
				virtual	float TranslateGlobalYToLocalY(float y);

			private:
				float m_windowOffsetX;
				float m_windowOffsetY;
				std::list<Eegeo::Windows::Input::IWindowsInputHandler*> inputHandlerDelegates;
				std::list<Eegeo::UI::NativeInput::IKeyboardInputKeyPressedHandler*> keyPressListeners;
			};
		}
	}
}
