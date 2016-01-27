set(headers ${headers} platform/Rendering/SceneModels/Resources
)
set(currsources
  platform/Rendering/SceneModels/Resources/CMakeLists.txt
  platform/Rendering/SceneModels/Resources/ISceneModelResourceProvider.h
  platform/Rendering/SceneModels/Resources/SceneModelMaterialResource.h
  platform/Rendering/SceneModels/Resources/SceneModelMeshResource.h
  platform/Rendering/SceneModels/Resources/SceneModelResourceBase.h
  platform/Rendering/SceneModels/Resources/SceneModelResourceRepository.h
  platform/Rendering/SceneModels/Resources/SceneModelTextureResource.h
  platform/Rendering/SceneModels/Resources/SceneModelTriStripMeshResource.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\SceneModels\\Resources FILES ${currsources})
