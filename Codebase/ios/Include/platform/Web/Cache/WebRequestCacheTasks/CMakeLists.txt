set(headers ${headers} platform/Web/Cache/WebRequestCacheTasks
)
set(currsources
  platform/Web/Cache/WebRequestCacheTasks/CacheStoreOperation.h
  platform/Web/Cache/WebRequestCacheTasks/CMakeLists.txt
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheLoadWorkItem.cpp
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheLoadWorkItem.h
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheLoadWorkItemPool.cpp
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheLoadWorkItemPool.h
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheStoreWorkItem.cpp
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheStoreWorkItem.h
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheStoreWorkItemPool.cpp
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheStoreWorkItemPool.h
  platform/Web/Cache/WebRequestCacheTasks/WebServiceCacheTasks.h
)
set(sources ${sources} ${currsources})
source_group(Cache\\WebRequestCacheTasks FILES ${currsources})
