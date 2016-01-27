// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFileIO.h"
#include "Types.h"
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <sys/stat.h>

struct AndroidNativeState;

namespace Eegeo
{
	namespace Android
	{
		class AndroidFileIO : public Eegeo::Helpers::IFileIO, protected Eegeo::NonCopyable
		{
		public:
			AndroidFileIO(AndroidNativeState* pState);
			AndroidFileIO(AndroidNativeState* pState, const std::set<std::string>& customDiretoryPaths);
			virtual ~AndroidFileIO();

			virtual bool OpenFile(std::fstream& stream, size_t& size, const std::string& name, std::ios_base::openmode mode=std::ifstream::in);
			virtual bool WriteFile(const Byte* data, size_t size, const std::string& name, std::ios_base::openmode mode=std::ifstream::out);
			virtual bool DeleteFile(const std::string& name);
			virtual bool Exists(const std::string& name);
			virtual bool TryStat(const std::string& name, Helpers::FileStat& out_filestat);
            virtual std::string GetAppFilePathname(const std::string& filename);

        private:
            void CopyDataFromAPK(const std::vector<std::string>& assetDirs);
            std::string QueryAppFileDirPath(AndroidNativeState& nativeState) const;

            AndroidNativeState* m_pState;
            std::string m_appFileDirPath;
		};
	}
}
