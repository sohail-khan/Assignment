set(headers ${headers} platform/Rendering/Filters
)
set(currsources
  platform/Rendering/Filters/CMakeLists.txt
  platform/Rendering/Filters/DefaultRenderableFilter.cpp
  platform/Rendering/Filters/DefaultRenderableFilter.h
  platform/Rendering/Filters/InteriorsRenderableFilter.cpp
  platform/Rendering/Filters/InteriorsRenderableFilter.h
  platform/Rendering/Filters/ISceneElementCriteriaFilterable.h
  platform/Rendering/Filters/PackedRenderableFilter.cpp
  platform/Rendering/Filters/PackedRenderableFilter.h
  platform/Rendering/Filters/PlaceNamesViewFilter.cpp
  platform/Rendering/Filters/PlaceNamesViewFilter.h
  platform/Rendering/Filters/RenderableRepository.cpp
  platform/Rendering/Filters/RenderableRepository.h
  platform/Rendering/Filters/SceneModelRenderableFilter.cpp
  platform/Rendering/Filters/SceneModelRenderableFilter.h
  platform/Rendering/Filters/ShadowPackedRenderableFilter.cpp
  platform/Rendering/Filters/ShadowPackedRenderableFilter.h
  platform/Rendering/Filters/SimpleRenderFilter.h
  platform/Rendering/Filters/WorldMeshRenderableFilter.cpp
  platform/Rendering/Filters/WorldMeshRenderableFilter.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\Filters FILES ${currsources})
