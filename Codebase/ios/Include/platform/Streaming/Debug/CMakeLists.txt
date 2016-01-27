set(headers ${headers} platform/Streaming/Debug
)
set(currsources
  platform/Streaming/Debug/CMakeLists.txt
  platform/Streaming/Debug/StreamingPipelineVisualiser.cpp
  platform/Streaming/Debug/StreamingPipelineVisualiser.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\Debug FILES ${currsources})
