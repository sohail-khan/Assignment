set(headers ${headers} platform/AnimatedObjects
)
set(currsources
  platform/AnimatedObjects/AnimatedObject.cpp
  platform/AnimatedObjects/AnimatedObject.h
  platform/AnimatedObjects/AnimatedObjects.h
  platform/AnimatedObjects/AnimatedObjectsController.cpp
  platform/AnimatedObjects/AnimatedObjectsController.h
  platform/AnimatedObjects/AnimatedObjectsRenderer.cpp
  platform/AnimatedObjects/AnimatedObjectsRenderer.h
  platform/AnimatedObjects/AnimatedObjectsRepository.cpp
  platform/AnimatedObjects/AnimatedObjectsRepository.h
  platform/AnimatedObjects/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\AnimatedObjects FILES ${currsources})
