set(headers ${headers} platform/Resources/Terrain/Collision
)
set(currsources
  platform/Resources/Terrain/Collision/CMakeLists.txt
  platform/Resources/Terrain/Collision/TerrainRayPicker.cpp
  platform/Resources/Terrain/Collision/TerrainRayPicker.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Terrain\\Collision FILES ${currsources})
