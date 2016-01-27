// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Cache.h"
#include "IHttpCache.h"
#include "Helpers.h"

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			class CachePruner
			{
			public:
				CachePruner(Helpers::IFileIO& fileIO);
				virtual ~CachePruner();

				void PruneToDiskSize(CacheModel& cacheModel, Eegeo::Helpers::CacheSize_t maxDiskSizeInBytes);

			private:
                Helpers::IFileIO& m_fileIO;
			};
		}
	}
}
