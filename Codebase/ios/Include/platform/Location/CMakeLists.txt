set(headers ${headers} platform/Location
)
set(currsources
  platform/Location/CMakeLists.txt
  platform/Location/DebugPlaceJump.cpp
  platform/Location/DebugPlaceJump.h
  platform/Location/IInterestPointProvider.h
  platform/Location/ILocationService.h
  platform/Location/Location.h
  platform/Location/NavigationService.cpp
  platform/Location/NavigationService.h
)
set(sources ${sources} ${currsources})
source_group(\\Location FILES ${currsources})
