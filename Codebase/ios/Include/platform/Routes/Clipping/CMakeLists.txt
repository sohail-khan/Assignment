set(headers ${headers} platform/Routes/Clipping
)
set(currsources
  platform/Routes/Clipping/ClippedRoute.h
  platform/Routes/Clipping/ClippedRouteSection.cpp
  platform/Routes/Clipping/ClippedRouteSection.h
  platform/Routes/Clipping/CMakeLists.txt
  platform/Routes/Clipping/RouteClippedLineSegment.h
  platform/Routes/Clipping/RouteClippingService.cpp
  platform/Routes/Clipping/RouteClippingService.h
  platform/Routes/Clipping/SplitPlanes.h
)
set(sources ${sources} ${currsources})
source_group(\\Routes\\Clipping FILES ${currsources})
