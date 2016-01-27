// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include <fstream>
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Windows
	{
		namespace Cache
		{
			class LegacyWindowsHttpCacheCleaner
			{
			public:
				LegacyWindowsHttpCacheCleaner(
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
