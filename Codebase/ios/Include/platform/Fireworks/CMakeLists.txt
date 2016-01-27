set(headers ${headers} platform/Fireworks
)
set(currsources
  platform/Fireworks/CMakeLists.txt
  platform/Fireworks/FireworkEmitter.cpp
  platform/Fireworks/FireworkEmitter.h
  platform/Fireworks/Fireworks.h
  platform/Fireworks/FireworksDisplay.cpp
  platform/Fireworks/FireworksDisplay.h
  platform/Fireworks/FireworksDisplayService.cpp
  platform/Fireworks/FireworksDisplayService.h
  platform/Fireworks/FireworksLocation.cpp
  platform/Fireworks/FireworksLocation.h
  platform/Fireworks/FireworksLocationConfiguration.h
  platform/Fireworks/FireworksLocationRepository.cpp
  platform/Fireworks/FireworksLocationRepository.h
  platform/Fireworks/FireworksRenderableFilter.cpp
  platform/Fireworks/FireworksRenderableFilter.h
  platform/Fireworks/FireworksSequence.cpp
  platform/Fireworks/FireworksSequence.h
  platform/Fireworks/FireworksSequenceBurstConfiguration.h
  platform/Fireworks/FireworksSequenceFactory.cpp
  platform/Fireworks/FireworksSequenceFactory.h
  platform/Fireworks/IFireworksLocation.h
  platform/Fireworks/IFireworksLocationRepository.h
)
set(sources ${sources} ${currsources})
source_group(\\Fireworks FILES ${currsources})
