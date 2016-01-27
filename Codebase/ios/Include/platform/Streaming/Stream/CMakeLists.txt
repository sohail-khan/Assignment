set(headers ${headers} platform/Streaming/Stream
)
set(currsources
  platform/Streaming/Stream/CMakeLists.txt
  platform/Streaming/Stream/IResourceStream.h
  platform/Streaming/Stream/IStreamingObserver.h
  platform/Streaming/Stream/LodStreamMap.cpp
  platform/Streaming/Stream/LodStreamMap.h
  platform/Streaming/Stream/LoggingResourceStream.cpp
  platform/Streaming/Stream/LoggingResourceStream.h
  platform/Streaming/Stream/MortonKey.cpp
  platform/Streaming/Stream/MortonKey.h
  platform/Streaming/Stream/MortonKeyAdjacency.cpp
  platform/Streaming/Stream/MortonKeyAdjacency.h
  platform/Streaming/Stream/MortonKeyFactoryHelpers.cpp
  platform/Streaming/Stream/MortonKeyFactoryHelpers.h
  platform/Streaming/Stream/MortonKeyLongLoader.cpp
  platform/Streaming/Stream/MortonKeyLongLoader.h
  platform/Streaming/Stream/PayloadSlotStream.h
  platform/Streaming/Stream/PayloadSlotStreamMap.cpp
  platform/Streaming/Stream/PayloadSlotStreamMap.h
  platform/Streaming/Stream/ResourceStreamBase.cpp
  platform/Streaming/Stream/ResourceStreamBase.h
  platform/Streaming/Stream/ResourceStreamComponent.cpp
  platform/Streaming/Stream/ResourceStreamComponent.h
  platform/Streaming/Stream/ResourceUrl.cpp
  platform/Streaming/Stream/ResourceUrl.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\Stream FILES ${currsources})
