// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once
#include "Types.h"
#include "WindowsDialogBox.h"
#include "WindowsDialogBoxParams.h"
#include "WindowsDialogBoxTemplate.h"

namespace Eegeo
{
	class WindowsDialogBoxBuilder
	{
		DialogBoxParams m_dialogBoxParams;
		std::vector<DialogBoxFunction> m_dialogBoxFunctions;
	public:

		WindowsDialogBox Build();
		void InitBox(const DialogBoxParams &dbParams);
		void AddFunction(const DialogBoxFunction &dbFunc);

	private:
		void WriteBox(const DialogBoxParams &dbParams, DialogTemplate& writer);

		void WriteFunction(const DialogBoxFunction &dbFunc, DialogTemplate& writer);
	};
}