set(headers ${headers} platform/Debug/Commands/Camera
)
set(currsources
  platform/Debug/Commands/Camera/CameraJumpCommand.cpp
  platform/Debug/Commands/Camera/CameraJumpCommand.h
  platform/Debug/Commands/Camera/CameraLocationCommand.cpp
  platform/Debug/Commands/Camera/CameraLocationCommand.h
  platform/Debug/Commands/Camera/CameraTiltToggleCommand.cpp
  platform/Debug/Commands/Camera/CameraTiltToggleCommand.h
  platform/Debug/Commands/Camera/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Camera FILES ${currsources})
