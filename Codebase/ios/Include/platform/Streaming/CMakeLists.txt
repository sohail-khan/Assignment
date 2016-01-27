set(headers ${headers} platform/Streaming
)
set(currsources
  platform/Streaming/CMakeLists.txt
  platform/Streaming/PayloadPlaceholderBuilder.cpp
  platform/Streaming/PayloadPlaceholderBuilder.h
  platform/Streaming/ResourceCeilingProvider.cpp
  platform/Streaming/ResourceCeilingProvider.h
  platform/Streaming/Streaming.h
  platform/Streaming/StreamingController.cpp
  platform/Streaming/StreamingController.h
  platform/Streaming/TerrainPlaceholderInserter.cpp
  platform/Streaming/TerrainPlaceholderInserter.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming FILES ${currsources})
include(platform/Streaming/BlockCoverageTrees/CMakeLists.txt)
include(platform/Streaming/CoverageTrees/CMakeLists.txt)
include(platform/Streaming/Debug/CMakeLists.txt)
include(platform/Streaming/Payload/CMakeLists.txt)
include(platform/Streaming/Prioritisers/CMakeLists.txt)
include(platform/Streaming/Quadtree/CMakeLists.txt)
include(platform/Streaming/SceneGraph/CMakeLists.txt)
include(platform/Streaming/Stream/CMakeLists.txt)
include(platform/Streaming/Volume/CMakeLists.txt)
