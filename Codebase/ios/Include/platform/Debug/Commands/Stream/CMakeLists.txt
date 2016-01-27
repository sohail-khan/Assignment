set(headers ${headers} platform/Debug/Commands/Stream
)
set(currsources
  platform/Debug/Commands/Stream/CMakeLists.txt
  platform/Debug/Commands/Stream/StreamListCommand.cpp
  platform/Debug/Commands/Stream/StreamListCommand.h
  platform/Debug/Commands/Stream/StreamStatsCommand.cpp
  platform/Debug/Commands/Stream/StreamStatsCommand.h
  platform/Debug/Commands/Stream/StreamToggleCommand.cpp
  platform/Debug/Commands/Stream/StreamToggleCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Stream FILES ${currsources})
