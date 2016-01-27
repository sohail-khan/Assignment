set(headers ${headers} platform/Modules/Data
)
set(currsources
  platform/Modules/Data/CMakeLists.txt
  platform/Modules/Data/DataModule.cpp
  platform/Modules/Data/DataModule.h
  platform/Modules/Data/GeofenceModule.cpp
  platform/Modules/Data/GeofenceModule.h
  platform/Modules/Data/HeatmapModule.cpp
  platform/Modules/Data/HeatmapModule.h
  platform/Modules/Data/PolyChartModule.cpp
  platform/Modules/Data/PolyChartModule.h
  platform/Modules/Data/StencilAreaModule.cpp
  platform/Modules/Data/StencilAreaModule.h
)
set(sources ${sources} ${currsources})
source_group(\\Modules\\Data FILES ${currsources})
