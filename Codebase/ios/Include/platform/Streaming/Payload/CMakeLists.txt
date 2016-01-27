set(headers ${headers} platform/Streaming/Payload
)
set(currsources
  platform/Streaming/Payload/BuildWorkItem.cpp
  platform/Streaming/Payload/BuildWorkItem.h
  platform/Streaming/Payload/CMakeLists.txt
  platform/Streaming/Payload/Payload.cpp
  platform/Streaming/Payload/Payload.h
  platform/Streaming/Payload/PayloadBuildManager.cpp
  platform/Streaming/Payload/PayloadBuildManager.h
  platform/Streaming/Payload/PayloadEvicter.cpp
  platform/Streaming/Payload/PayloadEvicter.h
  platform/Streaming/Payload/PayloadPool.cpp
  platform/Streaming/Payload/PayloadPool.h
  platform/Streaming/Payload/PayloadStateStats.cpp
  platform/Streaming/Payload/PayloadStateStats.h
  platform/Streaming/Payload/PayloadWebLoader.cpp
  platform/Streaming/Payload/PayloadWebLoader.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\Payload FILES ${currsources})
