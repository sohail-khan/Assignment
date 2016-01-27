// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <string>

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			class CacheRecord
			{
			public:
				CacheRecord();

				CacheRecord(
					const std::string& url,
					time_t firstRetrievedTime,
					time_t lastRetrievedTime,
					const std::string& etag,
					const std::string& lastModifiedTime,
					size_t headerDataSize,
					size_t bodyDataSize);

				virtual ~CacheRecord();

				const std::string& GetUrl() const;
				time_t GetFirstRetrievedTime() const;
				time_t GetLastRetrievedTime() const;
				const std::string& GetETag() const;
				const std::string& GetLastModified() const;
				size_t GetHeaderDataSize() const;
				size_t GetBodyDataSize() const;
				size_t GetSizeOnDisk() const;

			private:
				std::string m_url;
				std::string m_etag;
				time_t m_firstRetrievedTime;
				time_t m_lastRetrievedTime;
				std::string m_lastModified;
				size_t m_headerDataSize;
				size_t m_bodyDataSize;
			};
		}
	}
}
