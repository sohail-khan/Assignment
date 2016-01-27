// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFileIO.h"
#include "Types.h"
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <sys/stat.h>

struct WindowsNativeState;

namespace Eegeo
{
	namespace Windows
	{
		class WindowsFileIO : public Eegeo::Helpers::IFileIO, protected Eegeo::NonCopyable
		{
			WindowsNativeState* m_pState;


			std::string m_appFileDirPath;

			void CopyDataFromAPK(const std::vector<std::string>& assetDirs);

			std::string QueryAppFileDirPath(WindowsNativeState& nativeState) const;
		public:

			WindowsFileIO(WindowsNativeState* pState);
			WindowsFileIO(WindowsNativeState* pState, const std::set<std::string>& customDiretoryPaths);
			~WindowsFileIO();

			bool OpenFile(std::fstream& stream, size_t& size, const std::string& name, std::ios_base::openmode mode=std::ifstream::in);
			bool WriteFile(const Byte* data, size_t size, const std::string& name, std::ios_base::openmode mode=std::ifstream::out);
			bool DeleteFile(const std::string& name);
			bool Exists(const std::string& name);
			std::string GetAppFilePathname(const std::string& filename);
			bool TryStat(const std::string& name, Helpers::FileStat& out_s);
		};
	}
}
