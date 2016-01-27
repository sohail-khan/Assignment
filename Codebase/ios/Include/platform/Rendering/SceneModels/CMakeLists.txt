set(headers ${headers} platform/Rendering/SceneModels
)
set(currsources
  platform/Rendering/SceneModels/CMakeLists.txt
  platform/Rendering/SceneModels/SceneModel.cpp
  platform/Rendering/SceneModels/SceneModel.h
  platform/Rendering/SceneModels/SceneModelFactory.cpp
  platform/Rendering/SceneModels/SceneModelFactory.h
  platform/Rendering/SceneModels/SceneModelLoader.cpp
  platform/Rendering/SceneModels/SceneModelLoader.h
  platform/Rendering/SceneModels/SceneModelNode.cpp
  platform/Rendering/SceneModels/SceneModelNode.h
  platform/Rendering/SceneModels/SceneModelNodeVisitors.h
  platform/Rendering/SceneModels/SceneModelRenderableNode.cpp
  platform/Rendering/SceneModels/SceneModelRenderableNode.h
  platform/Rendering/SceneModels/SceneModelTransformHelpers.cpp
  platform/Rendering/SceneModels/SceneModelTransformHelpers.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\SceneModels FILES ${currsources})
include(platform/Rendering/SceneModels/Animation/CMakeLists.txt)
include(platform/Rendering/SceneModels/Resources/CMakeLists.txt)
