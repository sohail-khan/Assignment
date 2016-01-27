set(headers ${headers} platform/Debug/Commands/Stats
)
set(currsources
  platform/Debug/Commands/Stats/CMakeLists.txt
  platform/Debug/Commands/Stats/FpsStatsCommand.cpp
  platform/Debug/Commands/Stats/FpsStatsCommand.h
  platform/Debug/Commands/Stats/MemStatsCommand.cpp
  platform/Debug/Commands/Stats/MemStatsCommand.h
  platform/Debug/Commands/Stats/NetStatsCommand.cpp
  platform/Debug/Commands/Stats/NetStatsCommand.h
  platform/Debug/Commands/Stats/RenderStatsCommand.cpp
  platform/Debug/Commands/Stats/RenderStatsCommand.h
  platform/Debug/Commands/Stats/ResetStatsCommand.cpp
  platform/Debug/Commands/Stats/ResetStatsCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Stats FILES ${currsources})
