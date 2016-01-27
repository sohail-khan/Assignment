set(headers ${headers} platform/Resources/Terrain/Lcm
)
set(currsources
  platform/Resources/Terrain/Lcm/ChunkedLcmTerrainBuilder.cpp
  platform/Resources/Terrain/Lcm/ChunkedLcmTerrainBuilder.h
  platform/Resources/Terrain/Lcm/ChunkedLcmTerrainHeightLookup.cpp
  platform/Resources/Terrain/Lcm/ChunkedLcmTerrainHeightLookup.h
  platform/Resources/Terrain/Lcm/ChunkedTerrainLcmMissingResourceBuilder.cpp
  platform/Resources/Terrain/Lcm/ChunkedTerrainLcmMissingResourceBuilder.h
  platform/Resources/Terrain/Lcm/CMakeLists.txt
  platform/Resources/Terrain/Lcm/CulledHeightMesh.cpp
  platform/Resources/Terrain/Lcm/CulledHeightMesh.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Terrain\\Lcm FILES ${currsources})
