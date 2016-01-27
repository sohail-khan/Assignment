// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Cache.h"
#include "Helpers.h"
#include <iosfwd>

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			class CacheModelSerializer
			{
			public:
				CacheModelSerializer(Helpers::IFileIO& fileIO);
				virtual ~CacheModelSerializer();

				bool WriteToFile(const CacheModel& cacheModel, const std::string& filename);
				bool ReadFromFile(const std::string& filename, CacheModel& cacheModel);

			private:
				Helpers::IFileIO& m_fileIO;

				void WriteHeader(std::ostream& outputStream);
				bool TryReadHeader(std::istream& inputStream, unsigned int& out_version);

				void WriteFooter(std::ostream& outputStream);
				bool TryReadFooter(std::istream& inputStream);

				void WriteRecord(const CacheRecord& record, std::ostream& outputStream);
				CacheRecord ReadRecord(std::istream& inputStream, const u32 version);
			};
		}
	}
}
