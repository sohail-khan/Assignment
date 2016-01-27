set(headers ${headers} platform/Debug/BuildingFootprints
)
set(currsources
  platform/Debug/BuildingFootprints/CMakeLists.txt
  platform/Debug/BuildingFootprints/DebugBuildingFootprintsController.cpp
  platform/Debug/BuildingFootprints/DebugBuildingFootprintsController.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\BuildingFootprints FILES ${currsources})
