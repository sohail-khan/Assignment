set(headers ${headers} platform/Resources/Terrain/Raster
)
set(currsources
  platform/Resources/Terrain/Raster/CMakeLists.txt
  platform/Resources/Terrain/Raster/RasterTerrainBuilder.cpp
  platform/Resources/Terrain/Raster/RasterTerrainBuilder.h
  platform/Resources/Terrain/Raster/RasterTerrainConstants.cpp
  platform/Resources/Terrain/Raster/RasterTerrainConstants.h
  platform/Resources/Terrain/Raster/RasterTerrainHeightLookup.cpp
  platform/Resources/Terrain/Raster/RasterTerrainHeightLookup.h
  platform/Resources/Terrain/Raster/RasterTerrainParser.cpp
  platform/Resources/Terrain/Raster/RasterTerrainParser.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Terrain\\Raster FILES ${currsources})
