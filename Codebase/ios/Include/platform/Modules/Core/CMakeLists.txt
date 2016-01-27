set(headers ${headers} platform/Modules/Core
)
set(currsources
  platform/Modules/Core/AsyncLoadersModule.cpp
  platform/Modules/Core/AsyncLoadersModule.h
  platform/Modules/Core/CMakeLists.txt
  platform/Modules/Core/CoreModule.cpp
  platform/Modules/Core/CoreModule.h
  platform/Modules/Core/DebugRenderingModule.cpp
  platform/Modules/Core/DebugRenderingModule.h
  platform/Modules/Core/FontsModule.cpp
  platform/Modules/Core/FontsModule.h
  platform/Modules/Core/LightingModule.cpp
  platform/Modules/Core/LightingModule.h
  platform/Modules/Core/RenderingModule.cpp
  platform/Modules/Core/RenderingModule.h
  platform/Modules/Core/SceneModelsModule.cpp
  platform/Modules/Core/SceneModelsModule.h
)
set(sources ${sources} ${currsources})
source_group(\\Modules\\Core FILES ${currsources})
