set(headers ${headers} platform/Modules/Map
)
set(currsources
  platform/Modules/Map/CityThemesModule.cpp
  platform/Modules/Map/CityThemesModule.h
  platform/Modules/Map/CMakeLists.txt
  platform/Modules/Map/CoverageTreeModule.cpp
  platform/Modules/Map/CoverageTreeModule.h
  platform/Modules/Map/EnvironmentMaterialModule.cpp
  platform/Modules/Map/EnvironmentMaterialModule.h
  platform/Modules/Map/MapDebugModule.cpp
  platform/Modules/Map/MapDebugModule.h
  platform/Modules/Map/MapModule.cpp
  platform/Modules/Map/MapModule.h
  platform/Modules/Map/StreamingModule.cpp
  platform/Modules/Map/StreamingModule.h
  platform/Modules/Map/WeatherModule.cpp
  platform/Modules/Map/WeatherModule.h
)
set(sources ${sources} ${currsources})
source_group(\\Modules\\Map FILES ${currsources})
include(platform/Modules/Map/Layers/CMakeLists.txt)
