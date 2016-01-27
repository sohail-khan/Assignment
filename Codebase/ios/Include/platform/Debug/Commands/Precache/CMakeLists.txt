set(headers ${headers} platform/Debug/Commands/Precache
)
set(currsources
  platform/Debug/Commands/Precache/CMakeLists.txt
  platform/Debug/Commands/Precache/PrecacheCancelCommand.cpp
  platform/Debug/Commands/Precache/PrecacheCancelCommand.h
  platform/Debug/Commands/Precache/PrecacheStatusCommand.cpp
  platform/Debug/Commands/Precache/PrecacheStatusCommand.h
  platform/Debug/Commands/Precache/PrecacheViewCommand.cpp
  platform/Debug/Commands/Precache/PrecacheViewCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Precache FILES ${currsources})
