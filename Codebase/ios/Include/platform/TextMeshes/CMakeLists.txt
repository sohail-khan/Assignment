set(headers ${headers} platform/TextMeshes
)
set(currsources
  platform/TextMeshes/CMakeLists.txt
  platform/TextMeshes/InstancedTextMeshBuilder.cpp
  platform/TextMeshes/InstancedTextMeshBuilder.h
  platform/TextMeshes/PreTransformedTextMeshBuilder.cpp
  platform/TextMeshes/PreTransformedTextMeshBuilder.h
  platform/TextMeshes/TextMeshBuilder.cpp
  platform/TextMeshes/TextMeshBuilder.h
  platform/TextMeshes/TextMeshBuilderResult.h
  platform/TextMeshes/TextMeshes.h
  platform/TextMeshes/TextMeshHelpers.h
)
set(sources ${sources} ${currsources})
source_group(\\TextMeshes FILES ${currsources})
include(platform/TextMeshes/Internal/CMakeLists.txt)
