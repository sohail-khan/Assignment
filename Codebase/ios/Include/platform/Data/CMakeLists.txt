set(headers ${headers} platform/Data
)
set(currsources
  platform/Data/CMakeLists.txt
  platform/Data/DataEntityController.h
)
set(sources ${sources} ${currsources})
source_group(\\Data FILES ${currsources})
include(platform/Data/Geofencing/CMakeLists.txt)
include(platform/Data/GeoJSON/CMakeLists.txt)
include(platform/Data/Heatmaps/CMakeLists.txt)
include(platform/Data/PolyChart/CMakeLists.txt)
include(platform/Data/StencilArea/CMakeLists.txt)
