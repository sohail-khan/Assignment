set(headers ${headers} platform/Resources/Buildings
)
set(currsources
  platform/Resources/Buildings/Buildings.h
  platform/Resources/Buildings/BuildingStreaming.cpp
  platform/Resources/Buildings/BuildingStreaming.h
  platform/Resources/Buildings/ChunkedBuildingBuilder.cpp
  platform/Resources/Buildings/ChunkedBuildingBuilder.h
  platform/Resources/Buildings/CMakeLists.txt
  platform/Resources/Buildings/LandmarkToRenderableRepository.cpp
  platform/Resources/Buildings/LandmarkToRenderableRepository.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Buildings FILES ${currsources})
