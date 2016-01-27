// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"
#include "KeyboardInput.h"

namespace Eegeo
{
	namespace Windows
	{
		namespace Input
		{
			class IWindowsInputHandler
			{
			public:
				virtual ~IWindowsInputHandler() { }

				virtual void Event_TouchRotate 			(const AppInterface::RotateData& data)=0;
				virtual void Event_TouchRotate_Start	(const AppInterface::RotateData& data)=0;
				virtual void Event_TouchRotate_End 		(const AppInterface::RotateData& data)=0;

				virtual void Event_TouchPinch 			(const AppInterface::PinchData& data)=0;
				virtual void Event_TouchPinch_Start 	(const AppInterface::PinchData& data)=0;
				virtual void Event_TouchPinch_End 		(const AppInterface::PinchData& data)=0;

				virtual void Event_TouchPan				(const AppInterface::PanData& data)=0;
				virtual void Event_TouchPan_Start		(const AppInterface::PanData& data)=0;
				virtual void Event_TouchPan_End 		(const AppInterface::PanData& data)=0;

				virtual void Event_TouchTap				(const AppInterface::TapData& data)=0;
				virtual void Event_TouchDoubleTap		(const AppInterface::TapData& data)=0;

				virtual void Event_TouchDown 			(const AppInterface::TouchData& data)=0;
				virtual void Event_TouchMove 			(const AppInterface::TouchData& data)=0;
				virtual void Event_TouchUp 				(const AppInterface::TouchData& data)=0;
				virtual void Event_Zoom					(const AppInterface::ZoomData& data) = 0;

				virtual void Event_TiltStart			(const AppInterface::TiltData& data) = 0;
				virtual void Event_TiltEnd				(const AppInterface::TiltData& data) = 0;
				virtual void Event_Tilt					(const AppInterface::TiltData& data) = 0;

				virtual bool Event_KeyPress(const AppInterface::KeyboardData& data)=0;
				virtual void AddKeyPressListener(Eegeo::UI::NativeInput::IKeyboardInputKeyPressedHandler* handler)=0;
				virtual bool RemoveKeyPressListener(Eegeo::UI::NativeInput::IKeyboardInputKeyPressedHandler* handler)=0;

				virtual float TranslateGlobalXToLocalX(float x) { return x; }
				virtual float TranslateGlobalYToLocalY(float y) { return y; }
			};
		}
	}
}
