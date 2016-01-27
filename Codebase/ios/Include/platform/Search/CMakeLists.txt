set(headers ${headers} platform/Search
)
set(currsources
  platform/Search/CMakeLists.txt
  platform/Search/EegeoSearch.h
  platform/Search/SearchComponent.cpp
  platform/Search/SearchComponent.h
)
set(sources ${sources} ${currsources})
source_group(\\Search FILES ${currsources})
include(platform/Search/Service/CMakeLists.txt)
