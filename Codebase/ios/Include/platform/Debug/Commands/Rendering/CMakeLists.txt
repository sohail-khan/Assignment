set(headers ${headers} platform/Debug/Commands/Rendering
)
set(currsources
  platform/Debug/Commands/Rendering/CMakeLists.txt
  platform/Debug/Commands/Rendering/DrawDebugCommandHelpers.cpp
  platform/Debug/Commands/Rendering/DrawDebugCommandHelpers.h
  platform/Debug/Commands/Rendering/DrawDebugLineCommand.cpp
  platform/Debug/Commands/Rendering/DrawDebugLineCommand.h
  platform/Debug/Commands/Rendering/DrawDebugSphereCommand.cpp
  platform/Debug/Commands/Rendering/DrawDebugSphereCommand.h
  platform/Debug/Commands/Rendering/DrawDebugTextCommand.cpp
  platform/Debug/Commands/Rendering/DrawDebugTextCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Rendering FILES ${currsources})
