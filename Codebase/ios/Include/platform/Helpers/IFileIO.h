// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <sys/stat.h>
#include <fstream>
#include <string>

namespace Eegeo
{
	namespace Helpers
	{
        struct FileStat
        {
            long LastStatusModeChangeTime;
            long LastStatusModeChangeTimeNanoSecs;
            long LastModificationTime;
            long LastModificationTimeNanoSecs;
            long LastAccessTime;
            long LastAccessTimeNanoSecs;
            u64 FileSize;
        };

		class IFileIO
		{
		public:
			virtual ~IFileIO() { }

			virtual bool OpenFile(std::fstream& stream, size_t& size, const std::string& name, std::ios_base::openmode mode=std::ifstream::in)=0;
			virtual bool WriteFile(const Byte* data, size_t size, const std::string& name, std::ios_base::openmode mode=std::ifstream::out)=0;
			virtual bool DeleteFile(const std::string& name)=0;
			virtual bool Exists(const std::string& name)=0;
            virtual bool TryStat(const std::string& name, FileStat& s)=0;
            virtual std::string GetAppFilePathname(const std::string& filename)=0;
		};
	}
}
