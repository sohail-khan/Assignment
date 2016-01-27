// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once
#include <vector>
#include "EegeoWindowsGuard.h"
#include "IInputBoxDismissedHandler.h"
#include "WindowsDialogBoxTemplate.h"



namespace Eegeo
{
	const int EEGEO_INPUT_BOX_ID = 2007;
	
	enum DialogBoxControl
	{
		EEGEO_DIALOG_BOX_BUTTON = 0x0080FFFF,
		EEGEO_DIALOG_BOX_INPUT = 0x0081FFFF,
		EEGEO_DIALOG_BOX_STATIC = 0x0082FFFF
	};

	

	class WindowsDialogBox
	{
	public:
		WindowsDialogBox(const std::vector<BYTE>& _dialogTemplate);

		bool ShowDialogBox(HINSTANCE hinst, HWND hwnd, Eegeo::UI::NativeInput::IInputBoxDismissedHandler* callback);

	private:
		std::vector<BYTE> m_template;
	};
}