set(headers ${headers} platform/Debug/Picking
)
set(currsources
  platform/Debug/Picking/CMakeLists.txt
  platform/Debug/Picking/DebugPickingController.cpp
  platform/Debug/Picking/DebugPickingController.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Picking FILES ${currsources})
