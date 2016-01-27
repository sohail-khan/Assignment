set(headers ${headers} platform/CollisionVisualization
)
set(currsources
  platform/CollisionVisualization/CMakeLists.txt
  platform/CollisionVisualization/CollisionStreamingObserver.cpp
  platform/CollisionVisualization/CollisionStreamingObserver.h
  platform/CollisionVisualization/CollisionVisualization.h
  platform/CollisionVisualization/CollisionVisualizationHelpers.cpp
  platform/CollisionVisualization/CollisionVisualizationHelpers.h
  platform/CollisionVisualization/CollisionVisualizationMaterial.cpp
  platform/CollisionVisualization/CollisionVisualizationMaterial.h
  platform/CollisionVisualization/CollisionVisualizationRenderable.cpp
  platform/CollisionVisualization/CollisionVisualizationRenderable.h
  platform/CollisionVisualization/CollisionVisualizationRenderableFactory.cpp
  platform/CollisionVisualization/CollisionVisualizationRenderableFactory.h
  platform/CollisionVisualization/CollisionVisualizationRenderer.cpp
  platform/CollisionVisualization/CollisionVisualizationRenderer.h
  platform/CollisionVisualization/HighlightPickingController.cpp
  platform/CollisionVisualization/HighlightPickingController.h
  platform/CollisionVisualization/MaterialSelectionController.cpp
  platform/CollisionVisualization/MaterialSelectionController.h
  platform/CollisionVisualization/MaterialSelectionControllerConfig.h
  platform/CollisionVisualization/MaterialSelectionModel.cpp
  platform/CollisionVisualization/MaterialSelectionModel.h
  platform/CollisionVisualization/MaterialSelectionModelEntry.h
  platform/CollisionVisualization/MaterialSelectionRenderableFactory.cpp
  platform/CollisionVisualization/MaterialSelectionRenderableFactory.h
  platform/CollisionVisualization/MaterialSelectionView.cpp
  platform/CollisionVisualization/MaterialSelectionView.h
  platform/CollisionVisualization/PickingController.cpp
  platform/CollisionVisualization/PickingController.h
)
set(sources ${sources} ${currsources})
source_group(\\CollisionVisualization FILES ${currsources})
