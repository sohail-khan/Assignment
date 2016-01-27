set(headers ${headers} platform/Culling
)
set(currsources
  platform/Culling/CMakeLists.txt
  platform/Culling/Culling.h
  platform/Culling/CullingVolume.h
  platform/Culling/CullingVolumeTree.cpp
  platform/Culling/CullingVolumeTree.h
  platform/Culling/CullingVolumeVisibilityUpdater.cpp
  platform/Culling/CullingVolumeVisibilityUpdater.h
  platform/Culling/IndexBufferRange.h
  platform/Culling/IndexBufferRangeMerger.h
)
set(sources ${sources} ${currsources})
source_group(\\Culling FILES ${currsources})
