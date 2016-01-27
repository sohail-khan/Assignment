// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IHttpCache.h"
#include "Types.h"
#include "Helpers.h"
#include "Cache.h"
#include "CacheModel.h"
#include "CacheModelSerializer.h"
#include "CachePruner.h"
#include <vector>
#include <string>

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			class HttpCache : public Eegeo::Helpers::IHttpCache, protected Eegeo::NonCopyable
			{
			public:
				HttpCache(
                        Helpers::IFileIO& fileIO,
                        Eegeo::Helpers::CacheSize_t maxCacheSizeBytes=(4294967296ULL));

				virtual ~HttpCache() {}

                virtual void AddToCache(const Eegeo::Web::Cache::CacheRecord& cacheRecordToAdd);

                virtual void RemoveFromCache(const std::string& url);

                virtual bool TryGetCachedHeaderInfo(
                        const std::string& url,
                        std::string& out_cachedETag,
                        std::string& out_cachedLastModified);

                virtual void GetFileNameByUrl(std::string& name, const std::string& url);
                virtual void SetMaxCacheSize(Helpers::CacheSize_t size);
                virtual void ClearCache();
                virtual bool IsInCache(const std::string& url);
                virtual void FlushInMemoryCacheRepresentation(bool prune);
                virtual void ReloadCacheRepresentationFromStorage();
                virtual bool LoadLocallyCachedData(const std::string& url, std::vector<Byte>& out_buffer);
                virtual bool GetEnabled();
                virtual void SetEnabled(bool enabled);

            private:
                Helpers::IFileIO& m_fileIO;
                CacheModel m_cacheModel;
                CacheModelSerializer m_modelSerializer;
                CachePruner m_cachePruner;
                Eegeo::Helpers::CacheSize_t m_maxCacheSizeBytes;

                bool m_enabled;

                static const std::string Manifest;
			};
		}
	}
}
