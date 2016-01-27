// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFileIO.h"
#include "Types.h"
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <sys/stat.h>

namespace Eegeo
{
	namespace OSX
	{
		class OSXFileIO : public Eegeo::Helpers::IFileIO, protected Eegeo::NonCopyable
		{
		public:
			OSXFileIO(const std::string& basePath);
			virtual ~OSXFileIO();

			virtual bool OpenFile(std::fstream& stream, size_t& size, const std::string& name, std::ios_base::openmode mode=std::ifstream::in);
			virtual bool WriteFile(const Byte* data, size_t size, const std::string& name, std::ios_base::openmode mode=std::ifstream::out);
			virtual bool DeleteFile(const std::string& name);
			virtual bool Exists(const std::string& name);
			virtual bool TryStat(const std::string& name, Helpers::FileStat& out_filestat);
            virtual std::string GetAppFilePathname(const std::string& filename);
        private:
            std::string m_basePath;
		};
	}
}
