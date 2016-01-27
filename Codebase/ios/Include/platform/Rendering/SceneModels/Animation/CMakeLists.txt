set(headers ${headers} platform/Rendering/SceneModels/Animation
)
set(currsources
  platform/Rendering/SceneModels/Animation/CMakeLists.txt
  platform/Rendering/SceneModels/Animation/ISceneModelNodeAnimatedProperty.h
  platform/Rendering/SceneModels/Animation/ISceneModelNodeAnimation.h
  platform/Rendering/SceneModels/Animation/SceneModelAnimator.cpp
  platform/Rendering/SceneModels/Animation/SceneModelAnimator.h
  platform/Rendering/SceneModels/Animation/SceneModelNodeAnimatedProperty.h
  platform/Rendering/SceneModels/Animation/SceneModelNodeAnimation.cpp
  platform/Rendering/SceneModels/Animation/SceneModelNodeAnimation.h
  platform/Rendering/SceneModels/Animation/SceneModelNodeIndexedAnimatedProperty.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\SceneModels\\Animation FILES ${currsources})
