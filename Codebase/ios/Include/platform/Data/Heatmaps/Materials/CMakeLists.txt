set(headers ${headers} platform/Data/Heatmaps/Materials
)
set(currsources
  platform/Data/Heatmaps/Materials/CMakeLists.txt
  platform/Data/Heatmaps/Materials/HeatmapMaterial.cpp
  platform/Data/Heatmaps/Materials/HeatmapMaterial.h
  platform/Data/Heatmaps/Materials/HeatmapShader.cpp
  platform/Data/Heatmaps/Materials/HeatmapShader.h
)
set(sources ${sources} ${currsources})
source_group(\\Data\\Heatmaps\\Materials FILES ${currsources})
