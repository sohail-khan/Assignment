set(headers ${headers} platform/Data/Heatmaps
)
set(currsources
  platform/Data/Heatmaps/CMakeLists.txt
  platform/Data/Heatmaps/HeatmapController.h
  platform/Data/Heatmaps/HeatmapModel.cpp
  platform/Data/Heatmaps/HeatmapModel.h
  platform/Data/Heatmaps/HeatmapRenderable.cpp
  platform/Data/Heatmaps/HeatmapRenderable.h
  platform/Data/Heatmaps/HeatmapRenderer.h
  platform/Data/Heatmaps/Heatmaps.h
  platform/Data/Heatmaps/HeatmapView.cpp
  platform/Data/Heatmaps/HeatmapView.h
  platform/Data/Heatmaps/HeatmapViewFactory.cpp
  platform/Data/Heatmaps/HeatmapViewFactory.h
)
set(sources ${sources} ${currsources})
source_group(\\Data\\Heatmaps FILES ${currsources})
include(platform/Data/Heatmaps/Materials/CMakeLists.txt)
