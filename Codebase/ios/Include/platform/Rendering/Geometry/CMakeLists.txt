set(headers ${headers} platform/Rendering/Geometry
)
set(currsources
  platform/Rendering/Geometry/CMakeLists.txt
  platform/Rendering/Geometry/CubePrimitive.cpp
  platform/Rendering/Geometry/CubePrimitive.h
  platform/Rendering/Geometry/NineSlice.cpp
  platform/Rendering/Geometry/NineSlice.h
  platform/Rendering/Geometry/Quad.cpp
  platform/Rendering/Geometry/Quad.h
  platform/Rendering/Geometry/SpherePrimitive.cpp
  platform/Rendering/Geometry/SpherePrimitive.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\Geometry FILES ${currsources})
