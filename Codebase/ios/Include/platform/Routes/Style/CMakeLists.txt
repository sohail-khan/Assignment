set(headers ${headers} platform/Routes/Style
)
set(currsources
  platform/Routes/Style/CMakeLists.txt
  platform/Routes/Style/RouteStyle.cpp
  platform/Routes/Style/RouteStyle.h
)
set(sources ${sources} ${currsources})
source_group(\\Routes\\Style FILES ${currsources})
include(platform/Routes/Style/Thickness/CMakeLists.txt)
