set(headers ${headers} platform/Resources/Terrain/Heights
)
set(currsources
  platform/Resources/Terrain/Heights/CMakeLists.txt
  platform/Resources/Terrain/Heights/CollisionBvhTreeHeightQuery.cpp
  platform/Resources/Terrain/Heights/CollisionBvhTreeHeightQuery.h
  platform/Resources/Terrain/Heights/TerrainHeightLookup.h
  platform/Resources/Terrain/Heights/TerrainHeightProvider.cpp
  platform/Resources/Terrain/Heights/TerrainHeightProvider.h
  platform/Resources/Terrain/Heights/TerrainHeightRepository.cpp
  platform/Resources/Terrain/Heights/TerrainHeightRepository.h
  platform/Resources/Terrain/Heights/TerrainHeightsCallback.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Terrain\\Heights FILES ${currsources})
