set(headers ${headers} platform/Camera
)
set(currsources
  platform/Camera/Camera.h
  platform/Camera/CameraHelpers.cpp
  platform/Camera/CameraHelpers.h
  platform/Camera/CameraState.h
  platform/Camera/CMakeLists.txt
  platform/Camera/ICameraJumpController.h
  platform/Camera/RenderCamera.cpp
  platform/Camera/RenderCamera.h
)
set(sources ${sources} ${currsources})
source_group(\\Camera FILES ${currsources})
include(platform/Camera/GlobeCamera/CMakeLists.txt)
include(platform/Camera/SplinePlayback/CMakeLists.txt)
