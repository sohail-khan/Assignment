set(headers ${headers} platform/Camera/SplinePlayback
)
set(currsources
  platform/Camera/SplinePlayback/CameraSplinePlaybackController.cpp
  platform/Camera/SplinePlayback/CameraSplinePlaybackController.h
  platform/Camera/SplinePlayback/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\Camera\\SplinePlayback FILES ${currsources})
