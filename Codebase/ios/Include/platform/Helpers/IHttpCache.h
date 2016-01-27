// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Cache.h"
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Helpers
	{
        typedef unsigned long long CacheSize_t;
        
		class IHttpCache
		{
		public:
			virtual ~IHttpCache() { }

            virtual bool TryGetCachedHeaderInfo(
                    const std::string& url,
                    std::string& out_cachedETag,
                    std::string& out_cachedLastModified) = 0;
            
            virtual void GetFileNameByUrl(std::string& name, const std::string& url) = 0;
            virtual void SetMaxCacheSize(CacheSize_t size) = 0;
            virtual bool IsInCache(const std::string& url) = 0;
            
            virtual void ReloadCacheRepresentationFromStorage() = 0;
            virtual bool LoadLocallyCachedData(const std::string& url, std::vector<Byte>& out_buffer) = 0;
            
            virtual bool GetEnabled() = 0;
            virtual void SetEnabled(bool enabled) = 0;
          
            virtual void AddToCache(const Eegeo::Web::Cache::CacheRecord& cacheRecordToAdd) = 0;
            virtual void RemoveFromCache(const std::string& url) = 0;
            virtual void ClearCache() = 0;
            virtual void FlushInMemoryCacheRepresentation(bool prune) = 0;
		};
	}
}