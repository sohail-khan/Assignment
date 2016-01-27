set(headers ${headers} platform/Resources/Roads
)
set(currsources
  platform/Resources/Roads/ChunkedRoadBuilder.cpp
  platform/Resources/Roads/ChunkedRoadBuilder.h
  platform/Resources/Roads/CMakeLists.txt
  platform/Resources/Roads/ParsedNavGraph.cpp
  platform/Resources/Roads/ParsedNavGraph.h
  platform/Resources/Roads/ParsedRoadNames.h
  platform/Resources/Roads/RoadNamesFadeController.cpp
  platform/Resources/Roads/RoadNamesFadeController.h
  platform/Resources/Roads/RoadNamesMaterial.h
  platform/Resources/Roads/RoadNamesRenderable.h
  platform/Resources/Roads/RoadNamesRenderableFilter.h
  platform/Resources/Roads/Roads.h
  platform/Resources/Roads/RoadStreaming.cpp
  platform/Resources/Roads/RoadStreaming.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Roads FILES ${currsources})
include(platform/Resources/Roads/Navigation/CMakeLists.txt)
