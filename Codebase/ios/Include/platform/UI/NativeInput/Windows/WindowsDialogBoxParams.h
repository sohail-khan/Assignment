// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once
#include "Types.h"

namespace Eegeo
{
	struct DialogBoxParams
	{
		WORD dialogVersion;
		WORD extendedDialogTemplate;
		DWORD helpId;
		DWORD extendedStyle;
		DWORD windowStyle;
		WORD numOfControls;
		WORD x;
		WORD y;
		WORD width;
		WORD height;
		LPCWSTR menu;
		LPCWSTR defaultClass;
		LPCWSTR title;

		DialogBoxParams() :
			dialogVersion(1),
			extendedDialogTemplate(0xFFFF),
			helpId(0),
			extendedStyle(0),
			windowStyle(0),
			numOfControls(0),
			x(0),
			y(0),
			width(0),
			height(0),
			menu(L""),
			defaultClass(L""),
			title(L"TITLE")
		{

		}

	};

	struct DialogBoxFunction
	{
		DWORD helpId;
		DWORD extendedSytle;
		DWORD windowStyle;
		WORD x;
		WORD y;
		WORD width;
		WORD height;
		DWORD controlId;
		DWORD controlType;
		LPCWSTR text;
		WORD extraData;

		DialogBoxFunction() :
			helpId(0),
			extendedSytle(0),
			windowStyle(0),
			x(0),
			y(0),
			width(0),
			height(0),
			controlId(-1),
			controlType(0),
			text(L""),
			extraData(0)
		{

		}

	};
}