set(headers ${headers} platform/Streaming/SceneGraph
)
set(currsources
  platform/Streaming/SceneGraph/CMakeLists.txt
  platform/Streaming/SceneGraph/ResourceNode.cpp
  platform/Streaming/SceneGraph/ResourceNode.h
  platform/Streaming/SceneGraph/SceneGraphCellCallback.h
  platform/Streaming/SceneGraph/SceneGraphCellRepository.cpp
  platform/Streaming/SceneGraph/SceneGraphCellRepository.h
  platform/Streaming/SceneGraph/SceneGraphUpdater.cpp
  platform/Streaming/SceneGraph/SceneGraphUpdater.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\SceneGraph FILES ${currsources})
