set(headers ${headers} platform/Debug/DebugRendering/Renderers
)
set(currsources
  platform/Debug/DebugRendering/Renderers/CMakeLists.txt
  platform/Debug/DebugRendering/Renderers/DebugLineRendererEcef.cpp
  platform/Debug/DebugRendering/Renderers/DebugLineRendererEcef.h
  platform/Debug/DebugRendering/Renderers/DebugLineRendererScreenSpace.cpp
  platform/Debug/DebugRendering/Renderers/DebugLineRendererScreenSpace.h
  platform/Debug/DebugRendering/Renderers/DebugPrimitiveRendererEcef.cpp
  platform/Debug/DebugRendering/Renderers/DebugPrimitiveRendererEcef.h
  platform/Debug/DebugRendering/Renderers/DebugRendererHelpers.h
  platform/Debug/DebugRendering/Renderers/DebugTextRendererEcef.cpp
  platform/Debug/DebugRendering/Renderers/DebugTextRendererEcef.h
  platform/Debug/DebugRendering/Renderers/DebugTextRendererScreenSpace.cpp
  platform/Debug/DebugRendering/Renderers/DebugTextRendererScreenSpace.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\DebugRendering\\Renderers FILES ${currsources})
