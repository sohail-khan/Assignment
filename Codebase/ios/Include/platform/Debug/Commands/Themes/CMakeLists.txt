set(headers ${headers} platform/Debug/Commands/Themes
)
set(currsources
  platform/Debug/Commands/Themes/ChangeThemeStateCommand.cpp
  platform/Debug/Commands/Themes/ChangeThemeStateCommand.h
  platform/Debug/Commands/Themes/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Themes FILES ${currsources})
