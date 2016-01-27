// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AndroidNativeState.h"
#include <string>
#include "AppInfo.h"

namespace Eegeo
{
	namespace Android
	{
		Eegeo::AppInfo CreateAppInfo(AndroidNativeState& nativeState, const std::string &apiKey);
	}
}
