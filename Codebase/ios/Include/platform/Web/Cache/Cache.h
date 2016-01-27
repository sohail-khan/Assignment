// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
	namespace Web
	{
		namespace Cache
		{
			class CacheModel;
			class CacheRecord;
			class CacheModelSerializer;
			class HttpCache;
			class CacheHelpers;
			class CachePruner;
			class ILegacyCacheCleaner;

			namespace WebRequestCacheTasks
			{
				struct CacheStoreOperation;

				class WebServiceCacheLoadWorkItem;
				class WebServiceCacheLoadWorkItemCallback;
				class WebServiceCacheLoadWorkItemPool;

				class WebServiceCacheStoreWorkItem;
				class WebServiceCacheStoreWorkItemCallback;
				class WebServiceCacheStoreWorkItemPool;
			}
		}
	}
}
