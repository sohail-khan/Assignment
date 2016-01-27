// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include <iosfwd>
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Android
	{
		namespace Cache
		{
			class LegacyAndroidHttpCacheCleaner
			{
			public:
				LegacyAndroidHttpCacheCleaner(
						Helpers::IFileIO& fileIO
					);

				bool TryCleanLegacyCache();

			private:
				bool CleanVersion(std::fstream& stream, size_t& size, int cacheVersionNumber);
				bool CleanOriginalLegacyVersion(std::fstream& stream, size_t& size);
				bool RemoveFiles(std::vector<std::string>& filesToRemove);

				Helpers::IFileIO& m_fileIO;
			};
		}
	}
}
