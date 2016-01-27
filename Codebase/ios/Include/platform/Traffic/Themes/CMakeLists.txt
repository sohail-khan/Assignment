set(headers ${headers} platform/Traffic/Themes
)
set(currsources
  platform/Traffic/Themes/CMakeLists.txt
  platform/Traffic/Themes/ITrafficThemeModelObserver.cpp
  platform/Traffic/Themes/ITrafficThemeModelObserver.h
  platform/Traffic/Themes/TrafficThemeController.cpp
  platform/Traffic/Themes/TrafficThemeController.h
  platform/Traffic/Themes/TrafficThemeModel.cpp
  platform/Traffic/Themes/TrafficThemeModel.h
)
set(sources ${sources} ${currsources})
source_group(\\Traffic\\Themes FILES ${currsources})
