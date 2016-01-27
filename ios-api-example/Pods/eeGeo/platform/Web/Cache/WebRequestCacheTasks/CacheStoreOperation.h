// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <string>

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			namespace WebRequestCacheTasks
			{
				struct CacheStoreOperation
				{
					std::string url;

					Byte* headerBuffer;
					size_t headerSize;

					Byte* bodyBuffer;
					size_t bodySize;

					CacheStoreOperation()
					: headerBuffer(NULL)
					, headerSize(0)
					, bodyBuffer(NULL)
					, bodySize(0)
					{}
				};
			}
		}
	}
}
