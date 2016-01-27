//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "IFileIO.h"
#include "AndroidNativeState.h"

#include <string>

namespace Eegeo
{
	namespace Android
	{
		class AndroidCacheFileIO : public Eegeo::Helpers::IFileIO
		{
			std::string m_assetPathPrefix;

			std::string GetPath(const std::string& name) const;

		public:

			AndroidCacheFileIO(AndroidNativeState* pState);
			virtual ~AndroidCacheFileIO();

			virtual bool OpenFile(std::fstream& stream, size_t& size, const std::string& name, std::ios_base::openmode mode=std::ifstream::in);
			virtual bool WriteFile(const Byte* data, size_t size, const std::string& name, std::ios_base::openmode mode=std::ifstream::out);
			virtual bool DeleteFile(const std::string& name);
			virtual bool Exists(const std::string& name);
			virtual std::string GetAppFilePathname(const std::string& filename);
			virtual bool TryStat(const std::string& name, Helpers::FileStat& out_filestat);
		};

	}
}
