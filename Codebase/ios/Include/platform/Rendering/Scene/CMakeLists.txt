set(headers ${headers} platform/Rendering/Scene
)
set(currsources
  platform/Rendering/Scene/CMakeLists.txt
  platform/Rendering/Scene/ISceneElementFilterCriteria.h
  platform/Rendering/Scene/ISceneElementInGraphObserver.h
  platform/Rendering/Scene/ISceneElementObservable.h
  platform/Rendering/Scene/ISceneElementObserver.h
  platform/Rendering/Scene/ISceneElementRemover.h
  platform/Rendering/Scene/ISceneElementSource.h
  platform/Rendering/Scene/SceneElement.h
  platform/Rendering/Scene/SceneElementRepository.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\Scene FILES ${currsources})
