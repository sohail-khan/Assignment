// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			class CacheHelpers
			{
				public:
					static void UrlToCacheFilename(const std::string& url, std::string& out_filename);

			};
		}
	}
}
