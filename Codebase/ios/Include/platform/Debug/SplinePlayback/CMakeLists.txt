set(headers ${headers} platform/Debug/SplinePlayback
)
set(currsources
  platform/Debug/SplinePlayback/CMakeLists.txt
  platform/Debug/SplinePlayback/DebugCameraSplinePlaybackService.cpp
  platform/Debug/SplinePlayback/DebugCameraSplinePlaybackService.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\SplinePlayback FILES ${currsources})
