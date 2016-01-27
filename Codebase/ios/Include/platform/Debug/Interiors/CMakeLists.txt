set(headers ${headers} platform/Debug/Interiors
)
set(currsources
  platform/Debug/Interiors/CMakeLists.txt
  platform/Debug/Interiors/DebugInteriorsController.cpp
  platform/Debug/Interiors/DebugInteriorsController.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Interiors FILES ${currsources})
