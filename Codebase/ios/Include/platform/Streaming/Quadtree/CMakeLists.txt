set(headers ${headers} platform/Streaming/Quadtree
)
set(currsources
  platform/Streaming/Quadtree/CMakeLists.txt
  platform/Streaming/Quadtree/QuadTreeCube.cpp
  platform/Streaming/Quadtree/QuadTreeCube.h
  platform/Streaming/Quadtree/QuadTreeIntersection.cpp
  platform/Streaming/Quadtree/QuadTreeIntersection.h
  platform/Streaming/Quadtree/QuadTreeNode.cpp
  platform/Streaming/Quadtree/QuadTreeNode.h
  platform/Streaming/Quadtree/QuadTreeNodePool.cpp
  platform/Streaming/Quadtree/QuadTreeNodePool.h
  platform/Streaming/Quadtree/QuadTreeNodePoolItemFactory.cpp
  platform/Streaming/Quadtree/QuadTreeNodePoolItemFactory.h
  platform/Streaming/Quadtree/QuadTreeNodeVisitParams.h
  platform/Streaming/Quadtree/QuadTreeVisibilityUpdater.cpp
  platform/Streaming/Quadtree/QuadTreeVisibilityUpdater.h
  platform/Streaming/Quadtree/RedundantNodeEvicter.cpp
  platform/Streaming/Quadtree/RedundantNodeEvicter.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\Quadtree FILES ${currsources})
