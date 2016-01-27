if(${ANDROID})
set(headers ${headers} platform/Android/Cache
)
set(currsources
  platform/Android/Cache/CMakeLists.txt
  platform/Android/Cache/LegacyAndroidHttpCacheCleaner.cpp
  platform/Android/Cache/LegacyAndroidHttpCacheCleaner.h
)
set(sources ${sources} ${currsources})
source_group(\\Android\\Cache FILES ${currsources})
endif(${ANDROID})
