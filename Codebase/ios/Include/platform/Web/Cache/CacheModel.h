// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Cache.h"
#include "CacheRecord.h"
#include <string>
#include <map>
#include <vector>
#include <utility>

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			class CacheModel
			{
			public:
				CacheModel();
				virtual ~CacheModel();

				void Clear();
				bool ContainsUrl(const std::string& url) const;
				bool TryGetCacheRecord(const std::string& url, CacheRecord& out_cacheRecord) const;
				void Insert(const CacheRecord& cacheRecord);
                bool Remove(const std::string& url);
				bool ReplaceOrInsert(const CacheRecord& cacheRecord);

				void GetCacheRecords(std::vector<CacheRecord>& cacheRecords) const;
				size_t GetNumOfRecords() const;

			private:
				typedef std::map<std::string, CacheRecord> TUrlToCacheRecordMap;
				typedef std::pair<std::string, CacheRecord> TUrlCacheRecordPair;
				TUrlToCacheRecordMap m_cacheRecordsByUrl;

				size_t GetSizeOnDisk() const;
			};
		}
	}
}

