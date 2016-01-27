if(${WINDOWS})
set(headers ${headers} platform/Windows/Cache
)
set(currsources
  platform/Windows/Cache/CMakeLists.txt
  platform/Windows/Cache/LegacyWindowsHttpCacheCleaner.cpp
  platform/Windows/Cache/LegacyWindowsHttpCacheCleaner.h
)
set(sources ${sources} ${currsources})
source_group(\\Windows\\Cache FILES ${currsources})
endif(${WINDOWS})
