set(headers ${headers} platform/Debug
)
set(currsources
  platform/Debug/CMakeLists.txt
  platform/Debug/DebugDecl.h
  platform/Debug/DebugRenderable.cpp
  platform/Debug/DebugRenderable.h
  platform/Debug/DebugRendering.h
  platform/Debug/DebugShader.cpp
  platform/Debug/DebugShader.h
  platform/Debug/DebugStats.cpp
  platform/Debug/DebugStats.h
  platform/Debug/DebugValues.cpp
  platform/Debug/DebugValues.h
  platform/Debug/FrameTimer.cpp
  platform/Debug/FrameTimer.h
  platform/Debug/FrameTimerVisualiser.cpp
  platform/Debug/FrameTimerVisualiser.h
  platform/Debug/IDebugStats.h
  platform/Debug/IMemoryStats.h
  platform/Debug/NetworkBandwidthStats.h
  platform/Debug/SphereMesh.cpp
  platform/Debug/SphereMesh.h
  platform/Debug/SummaryStats.cpp
  platform/Debug/SummaryStats.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug FILES ${currsources})
include(platform/Debug/BuildingFootprints/CMakeLists.txt)
include(platform/Debug/Commands/CMakeLists.txt)
include(platform/Debug/DebugRendering/CMakeLists.txt)
include(platform/Debug/DebugServer/CMakeLists.txt)
include(platform/Debug/Interiors/CMakeLists.txt)
include(platform/Debug/Picking/CMakeLists.txt)
include(platform/Debug/Profile/CMakeLists.txt)
include(platform/Debug/SplinePlayback/CMakeLists.txt)
