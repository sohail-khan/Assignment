set(headers ${headers} platform/Streaming/Volume
)
set(currsources
  platform/Streaming/Volume/CameraFrustumStreamingVolume.cpp
  platform/Streaming/Volume/CameraFrustumStreamingVolume.h
  platform/Streaming/Volume/CMakeLists.txt
  platform/Streaming/Volume/FrustumStreamingVolume.cpp
  platform/Streaming/Volume/FrustumStreamingVolume.h
  platform/Streaming/Volume/IFrustumVolumeProvider.h
  platform/Streaming/Volume/IStreamingVolume.h
  platform/Streaming/Volume/StreamingVolumeController.cpp
  platform/Streaming/Volume/StreamingVolumeController.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\Volume FILES ${currsources})
