set(headers ${headers} platform/Web/Cache
)
set(currsources
  platform/Web/Cache/Cache.h
  platform/Web/Cache/CacheHelpers.cpp
  platform/Web/Cache/CacheHelpers.h
  platform/Web/Cache/CacheModel.cpp
  platform/Web/Cache/CacheModel.h
  platform/Web/Cache/CacheModelSerializer.cpp
  platform/Web/Cache/CacheModelSerializer.h
  platform/Web/Cache/CachePruner.cpp
  platform/Web/Cache/CachePruner.h
  platform/Web/Cache/CacheRecord.cpp
  platform/Web/Cache/CacheRecord.h
  platform/Web/Cache/CMakeLists.txt
  platform/Web/Cache/HttpCache.cpp
  platform/Web/Cache/HttpCache.h
)
set(sources ${sources} ${currsources})
source_group(Cache FILES ${currsources})
include(platform/Web/Cache/WebRequestCacheTasks/CMakeLists.txt)
