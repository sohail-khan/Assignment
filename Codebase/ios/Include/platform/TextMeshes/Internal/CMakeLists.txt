set(headers ${headers} platform/TextMeshes/Internal
)
set(currsources
  platform/TextMeshes/Internal/CharacterEntry.h
  platform/TextMeshes/Internal/CMakeLists.txt
  platform/TextMeshes/Internal/InstancedTextMeshGenerator.cpp
  platform/TextMeshes/Internal/InstancedTextMeshGenerator.h
  platform/TextMeshes/Internal/PreTransformedTextMeshGenerator.cpp
  platform/TextMeshes/Internal/PreTransformedTextMeshGenerator.h
  platform/TextMeshes/Internal/ScratchGeometry.cpp
  platform/TextMeshes/Internal/ScratchGeometry.h
  platform/TextMeshes/Internal/StringEntry.h
  platform/TextMeshes/Internal/TextMeshGenerator.cpp
  platform/TextMeshes/Internal/TextMeshGenerator.h
)
set(sources ${sources} ${currsources})
source_group(\\TextMeshes\\Internal FILES ${currsources})
