set(headers ${headers} platform/Debug/Commands/Profile
)
set(currsources
  platform/Debug/Commands/Profile/CMakeLists.txt
  platform/Debug/Commands/Profile/PerformanceTestBeginCommand.cpp
  platform/Debug/Commands/Profile/PerformanceTestBeginCommand.h
  platform/Debug/Commands/Profile/PerformanceTestRegisterSplineCommand.cpp
  platform/Debug/Commands/Profile/PerformanceTestRegisterSplineCommand.h
  platform/Debug/Commands/Profile/ProfileEnableCommand.cpp
  platform/Debug/Commands/Profile/ProfileEnableCommand.h
  platform/Debug/Commands/Profile/ProfileShowCommand.cpp
  platform/Debug/Commands/Profile/ProfileShowCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Profile FILES ${currsources})
