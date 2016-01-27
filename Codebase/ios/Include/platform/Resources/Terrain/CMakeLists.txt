set(headers ${headers} platform/Resources/Terrain
)
set(currsources
  platform/Resources/Terrain/CMakeLists.txt
  platform/Resources/Terrain/Terrain.h
  platform/Resources/Terrain/TerrainStreaming.cpp
  platform/Resources/Terrain/TerrainStreaming.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Terrain FILES ${currsources})
include(platform/Resources/Terrain/Collision/CMakeLists.txt)
include(platform/Resources/Terrain/Heights/CMakeLists.txt)
include(platform/Resources/Terrain/Lcm/CMakeLists.txt)
include(platform/Resources/Terrain/Placeholder/CMakeLists.txt)
include(platform/Resources/Terrain/Raster/CMakeLists.txt)
