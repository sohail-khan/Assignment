set(headers ${headers} platform/Modules
)
set(currsources
  platform/Modules/AnimatedObjectsModule.cpp
  platform/Modules/AnimatedObjectsModule.h
  platform/Modules/BuildingFootprintsModule.cpp
  platform/Modules/BuildingFootprintsModule.h
  platform/Modules/CMakeLists.txt
  platform/Modules/CollisionVisualizationModule.cpp
  platform/Modules/CollisionVisualizationModule.h
  platform/Modules/FireworksModule.cpp
  platform/Modules/FireworksModule.h
  platform/Modules/IPlatformAbstractionModule.h
  platform/Modules/Modules.h
  platform/Modules/RoutesModule.cpp
  platform/Modules/RoutesModule.h
  platform/Modules/TrafficModule.cpp
  platform/Modules/TrafficModule.h
)
set(sources ${sources} ${currsources})
source_group(\\Modules FILES ${currsources})
include(platform/Modules/Core/CMakeLists.txt)
include(platform/Modules/Data/CMakeLists.txt)
include(platform/Modules/Map/CMakeLists.txt)
