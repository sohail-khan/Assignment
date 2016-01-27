// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IPlatformConfigBuilder.h"
#include "PlatformConfig.h"
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Android
	{
		class AndroidPlatformConfigBuilder : public Config::IPlatformConfigBuilder
		{
		public:

			AndroidPlatformConfigBuilder(std::string deviceModel);

			Config::PlatformConfig Build();

		private:

			std::string m_deviceModel;

			const std::vector<std::string> m_devicesBufferPoolUnsupported;
			const std::vector<std::string> m_devices565MipmapsUnsupported;

			Config::PlatformConfig BuildDefaultConfig();
		};

	}
}
