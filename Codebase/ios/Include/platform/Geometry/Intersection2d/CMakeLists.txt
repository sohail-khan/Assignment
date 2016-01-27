set(headers ${headers} platform/Geometry/Intersection2d
)
set(currsources
  platform/Geometry/Intersection2d/CMakeLists.txt
  platform/Geometry/Intersection2d/Intersection2d.h
  platform/Geometry/Intersection2d/Lines2d.cpp
  platform/Geometry/Intersection2d/LineSegments2d.cpp
)
set(sources ${sources} ${currsources})
source_group(\\Geometry\\Intersection2d FILES ${currsources})
