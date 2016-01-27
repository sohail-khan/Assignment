// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IPlatformConfigBuilder.h"
#include "PlatformConfig.h"
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Windows
	{
		class WindowsPlatformConfigBuilder : public Config::IPlatformConfigBuilder
		{
		public:

			WindowsPlatformConfigBuilder(std::string deviceModel);

			Config::PlatformConfig Build();

		private:

			std::string m_deviceModel;

			const std::vector<std::string> m_devicesBufferPoolUnsupported;
			const std::vector<std::string> m_devices565MipmapsUnsupported;

			Config::PlatformConfig BuildDefaultConfig();
		};

	}
}
