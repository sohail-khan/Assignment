// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFileIO.h"
#include <sys/stat.h>
#include "Types.h"
#include <string>

namespace Eegeo
{
    namespace iOS
    {
        class iOSFileIO : public Eegeo::Helpers::IFileIO, protected Eegeo::NonCopyable
        {
        public:
            iOSFileIO();
            virtual ~iOSFileIO();
            virtual bool GetUrl(const std::string& name, char* fileURL);
            
            virtual bool OpenFile(std::fstream& stream, size_t& size, const std::string& name, std::ios_base::openmode mode=std::ifstream::in);
			virtual bool WriteFile(const Byte* data, size_t size, const std::string& name, std::ios_base::openmode mode=std::ifstream::out);
			virtual bool DeleteFile(const std::string& name);
			virtual bool Exists(const std::string& name);
            virtual bool TryStat(const std::string& name, Helpers::FileStat& out_filestat);
            virtual std::string GetAppFilePathname(const std::string& filename);
        };
    }
}
