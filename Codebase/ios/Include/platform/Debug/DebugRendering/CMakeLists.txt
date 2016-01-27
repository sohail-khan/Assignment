set(headers ${headers} platform/Debug/DebugRendering
)
set(currsources
  platform/Debug/DebugRendering/CMakeLists.txt
  platform/Debug/DebugRendering/DebugLineRenderable.cpp
  platform/Debug/DebugRendering/DebugLineRenderable.h
  platform/Debug/DebugRendering/DebugPrimitiveRenderable.cpp
  platform/Debug/DebugRendering/DebugPrimitiveRenderable.h
  platform/Debug/DebugRendering/DebugRenderableBase.cpp
  platform/Debug/DebugRendering/DebugRenderableBase.h
  platform/Debug/DebugRendering/DebugRenderer.cpp
  platform/Debug/DebugRendering/DebugRenderer.h
  platform/Debug/DebugRendering/DebugSphereData.h
  platform/Debug/DebugRendering/DebugTextRenderable.cpp
  platform/Debug/DebugRendering/DebugTextRenderable.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\DebugRendering FILES ${currsources})
include(platform/Debug/DebugRendering/Renderers/CMakeLists.txt)
