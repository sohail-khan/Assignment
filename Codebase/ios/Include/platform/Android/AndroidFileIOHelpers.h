// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include <string>

namespace Eegeo
{
	namespace Android
	{
		namespace FileIOHelpers
		{
			bool MakeDirIfNotExists(const std::string& path);
            void FileStatFromStat(const struct stat& stat, Eegeo::Helpers::FileStat& out_filestat);
		}
    }
}
