IF(NOT WINDOWS)
set(headers ${headers} platform/Debug/DebugServer
)
set(currsources
  platform/Debug/DebugServer/CMakeLists.txt
  platform/Debug/DebugServer/CommandServer.cpp
  platform/Debug/DebugServer/CommandServer.h
  platform/Debug/DebugServer/CommandServerModule.h
  platform/Debug/DebugServer/DefaultCommandsModule.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\DebugServer FILES ${currsources})
endif(NOT WINDOWS)