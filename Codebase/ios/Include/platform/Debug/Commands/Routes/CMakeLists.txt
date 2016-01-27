set(headers ${headers} platform/Debug/Commands/Routes
)
set(currsources
  platform/Debug/Commands/Routes/CMakeLists.txt
  platform/Debug/Commands/Routes/NewRouteCommand.cpp
  platform/Debug/Commands/Routes/NewRouteCommand.h
  platform/Debug/Commands/Routes/RouteFittingCommand.cpp
  platform/Debug/Commands/Routes/RouteFittingCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Routes FILES ${currsources})
