// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "WindowsNativeState.h"
#include <string>
#include "AppInfo.h"

namespace Eegeo
{
	namespace Windows
	{
		Eegeo::AppInfo CreateAppInfo(WindowsNativeState& nativeState, const std::string &apiKey);
	}
}
