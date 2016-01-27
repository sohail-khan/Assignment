set(headers ${headers} platform/Weather
)
set(currsources
  platform/Weather/CMakeLists.txt
  platform/Weather/Weather.h
  platform/Weather/WeatherOverlayController.cpp
  platform/Weather/WeatherOverlayController.h
  platform/Weather/WeatherOverlayRenderer.cpp
  platform/Weather/WeatherOverlayRenderer.h
)
set(sources ${sources} ${currsources})
source_group(\\Weather FILES ${currsources})
