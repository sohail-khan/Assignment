// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IPlatformConfigBuilder.h"
#include "PlatformConfig.h"
#include <string>
#include <vector>

namespace Eegeo
{
	namespace OSX
	{
		class OSXPlatformConfigBuilder : public Config::IPlatformConfigBuilder
		{
		public:
			Config::PlatformConfig Build();

		private:
			Config::PlatformConfig BuildDefaultConfig();
		};

	}
}
