set(headers ${headers} platform/Resources/Terrain/Placeholder
)
set(currsources
  platform/Resources/Terrain/Placeholder/CMakeLists.txt
  platform/Resources/Terrain/Placeholder/TerrainPlaceholderBuilder.cpp
  platform/Resources/Terrain/Placeholder/TerrainPlaceholderBuilder.h
  platform/Resources/Terrain/Placeholder/TerrainPlaceholderConstants.cpp
  platform/Resources/Terrain/Placeholder/TerrainPlaceholderConstants.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Terrain\\Placeholder FILES ${currsources})
